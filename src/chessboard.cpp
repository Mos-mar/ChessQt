//Custom headers and forward declaration
#include "chessboard.h"
#include "./ui_chessboard.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "piece.h"
#include "queen.h"
#include "rook.h"

//Qt & CPP includes
#include <QDebug>
#include <iostream>


ChessBoard::ChessBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessBoard)
{
    ui->setupUi(this);
    initializeBoardAndPieces();
    this->update(); //Qt actually handle the drawing and will call void paintEvent(QPaintEvent *event) on its own.


}

void ChessBoard::initializeBoardAndPieces()
{
  for(int i = 0 ; i <  8 ; i++)
  {
    for(int j = 0 ; j < 8 ; j++)
    {
      Color squareColor = (i+j) % 2 == 0 ? Color::WHITE : Color::BLACK;
      board[i][j] = std::make_unique<Square>(squareColor);
    }
  }
  initializeBlackPieces();
  initializeWhitePieces();

}

void ChessBoard::initializeBlackPieces()
{
  for(int i = 0 ; i < 8 ; i++)
  {
     board[1][i]->setPiece(std::make_unique<Pawn>(Color::BLACK));
  }

    board[0][0]->setPiece(std::make_unique<Rook>(Color::BLACK));
    board[0][1]->setPiece(std::make_unique<Knight>(Color::BLACK));
    board[0][2]->setPiece(std::make_unique<Bishop>(Color::BLACK));
    board[0][3]->setPiece(std::make_unique<Queen>(Color::BLACK));
    board[0][4]->setPiece(std::make_unique<King>(Color::BLACK));
    board[0][5]->setPiece(std::make_unique<Bishop>(Color::BLACK));
    board[0][6]->setPiece(std::make_unique<Knight>(Color::BLACK));
    board[0][7]->setPiece(std::make_unique<Rook>(Color::BLACK));

}

void ChessBoard::initializeWhitePieces()
{
    for(int i = 0 ; i < 8 ; i++)
    {
      board[6][i]->setPiece(std::make_unique<Pawn>(Color::WHITE));
    }

    board[7][0]->setPiece(std::make_unique<Rook>(Color::WHITE));
    board[7][1]->setPiece(std::make_unique<Knight>(Color::WHITE));
    board[7][2]->setPiece(std::make_unique<Bishop>(Color::WHITE));
    board[7][3]->setPiece(std::make_unique<Queen>(Color::WHITE));
    board[7][4]->setPiece(std::make_unique<King>(Color::WHITE));
    board[7][5]->setPiece(std::make_unique<Bishop>(Color::WHITE));
    board[7][6]->setPiece(std::make_unique<Knight>(Color::WHITE));
    board[7][7]->setPiece(std::make_unique<Rook>(Color::WHITE));

}


void ChessBoard::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  int squareSize = 80;

  for(int i = 0 ; i <  8 ; i++)
  {
    for(int j = 0 ; j < 8 ; j++)
    {
        QRect rect(j * squareSize, i * squareSize, squareSize,squareSize);
        QColor color = board[i][j]->color == Color::WHITE ? Qt::white : Qt::darkGray;
        painter.fillRect(rect,color);
        painter.drawRect(rect);

    }
  }


}


bool ChessBoard::movePiece(Player currentPlayer)
{

}

ChessBoard::~ChessBoard()
{
    delete ui;
}



