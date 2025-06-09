#include "boardWidget.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include "piece.h"

#include <QPainter>
#include <QMouseEvent>
#include <QPixmap>
#include <QDebug>

BoardWidget::BoardWidget(QWidget* parent)
    : QWidget(parent),
      whitePlayer(Color::WHITE),
      blackPlayer(Color::BLACK),
      currentPlayer(&whitePlayer),
      pieceSelected(false)
{
    initializeBoardAndPieces();
    setFixedSize(640, 640); // 8x8 board with 80px squares
}

void BoardWidget::initializeBoardAndPieces()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Color color = (i + j) % 2 == 0 ? Color::WHITE : Color::BLACK;
            board[i][j] = std::make_unique<Square>(color);
        }
    }

    // Black pieces
    board[0][0]->setPiece(std::make_unique<Rook>(Color::BLACK));
    board[0][1]->setPiece(std::make_unique<Knight>(Color::BLACK));
    board[0][2]->setPiece(std::make_unique<Bishop>(Color::BLACK));
    board[0][3]->setPiece(std::make_unique<Queen>(Color::BLACK));
    board[0][4]->setPiece(std::make_unique<King>(Color::BLACK));
    board[0][5]->setPiece(std::make_unique<Bishop>(Color::BLACK));
    board[0][6]->setPiece(std::make_unique<Knight>(Color::BLACK));
    board[0][7]->setPiece(std::make_unique<Rook>(Color::BLACK));
    for (int i = 0; i < 8; ++i)
        board[1][i]->setPiece(std::make_unique<Pawn>(Color::BLACK));

    // White pieces
    board[7][0]->setPiece(std::make_unique<Rook>(Color::WHITE));
    board[7][1]->setPiece(std::make_unique<Knight>(Color::WHITE));
    board[7][2]->setPiece(std::make_unique<Bishop>(Color::WHITE));
    board[7][3]->setPiece(std::make_unique<Queen>(Color::WHITE));
    board[7][4]->setPiece(std::make_unique<King>(Color::WHITE));
    board[7][5]->setPiece(std::make_unique<Bishop>(Color::WHITE));
    board[7][6]->setPiece(std::make_unique<Knight>(Color::WHITE));
    board[7][7]->setPiece(std::make_unique<Rook>(Color::WHITE));
    for (int i = 0; i < 8; ++i)
        board[6][i]->setPiece(std::make_unique<Pawn>(Color::WHITE));
}

void BoardWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    int squareSize = width() / 8;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            QRect rect(j * squareSize, i * squareSize, squareSize, squareSize);
            QColor color = board[i][j]->color == Color::WHITE ? QColor(245, 222, 179) : QColor(160, 82, 45);
            painter.fillRect(rect, color);
            painter.drawRect(rect);

            Piece* piece = board[i][j]->getPiece();
            if (piece)
            {
                QPixmap pix(piece->getImagePath());
                if (!pix.isNull())
                {
                    painter.drawPixmap(rect, pix.scaled(squareSize, squareSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                }
                else
                {
                    qWarning() << "Failed to load image:" << piece->getImagePath();
                }
            }
        }
    }
}

void BoardWidget::mousePressEvent(QMouseEvent* event)
{
    int squareSize = width() / 8;
    int col = event->pos().x() / squareSize;
    int row = event->pos().y() / squareSize;

    if (!Piece::isWithingGrid(row, col)) return;

    if (!pieceSelected)
    {
        Piece* clickedPiece = board[row][col]->getPiece();//less writing in the below if()
        //first click : selects piece
        if (clickedPiece && clickedPiece->getColor() == currentPlayer->get_color())
        {
            selectedSquare = {row, col};
            pieceSelected = true;
        }
    }
    else
    {
        //second click : try to move
        int startRow = selectedSquare.first;
        int startCol = selectedSquare.second;

        if (movePiece(currentPlayer, startRow, startCol, row, col))
        {
            currentPlayer = (currentPlayer == &whitePlayer) ? &blackPlayer : &whitePlayer;
            update(); //auto call paintEvent() and repaint the board
        }

        pieceSelected = false;  // reset click state either way
    }
}

bool BoardWidget::movePiece(Player* player, int startRow, int startCol, int endRow, int endCol)
{
    if (!Piece::isWithingGrid(endRow, endCol)) return false;

    Piece* pieceToMove = board[startRow][startCol]->getPiece();
    if (!pieceToMove) return false;
    if (pieceToMove->getColor() != player->get_color()) return false;

    //Creating a raw board and filling it with board from .h so i can pass i in isValidMove()
    Square* rawBoard[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            rawBoard[i][j] = board[i][j].get();

    if (pieceToMove->isValidMove(startRow, startCol, endRow, endCol, rawBoard))
    {
        Piece* destinationPiece = board[endRow][endCol]->getPiece();
        if (destinationPiece && destinationPiece->getColor() != pieceToMove->getColor())
        {
            board[endRow][endCol]->setPiece(nullptr); // capture
        }

        board[endRow][endCol]->setPiece(std::move(board[startRow][startCol]->getPiecePtr()));
        board[startRow][startCol]->setPiece(nullptr); //clear original piece;
        return true;
    }

    return false;
}


