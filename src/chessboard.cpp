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
    ,whitePlayer(Color::WHITE)
    ,blackPlayer(Color::BLACK)
{
    ui->setupUi(this);
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
    setCentralWidget(nullptr);  // Make this window "paintable" and responsive
    initializeBoardAndPieces();
    currentPlayer = &whitePlayer;
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
        QColor color = board[i][j]->color == Color::WHITE ? QColor(245, 222, 179) :  QColor(160, 80, 50);
        painter.fillRect(rect,color);
        painter.drawRect(rect);

        if(this->board[i][j]->getPiece() != nullptr)
        {
            QString path = board[i][j]->getPiece()->getImagePath();
            qDebug() << "Trying to load image from:" << path;
            QPixmap pix(path);
            if (pix.isNull())
            {
              qWarning() << "Failed to load pixmap from:" << path;
            }
            painter.drawPixmap(rect, pix.scaled(squareSize,squareSize,Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
  }


}


bool ChessBoard::movePiece(Player currentPlayer,int startRow, int startCol, int endRow, int endCol)
{

    if(!Piece::isWithingGrid(endRow,endCol))
   {
    return false;
   }

   Piece* pieceToMove = board[startRow][startCol]->getPiece();

   if(pieceToMove == nullptr)
   {
    std::cout << "There's no piece at the specified starting position." << std::endl;
    return false;
   }

   if(pieceToMove->getColor() != currentPlayer.get_color())
   {
    std::cout << "It's not your turn to move this piece." << std::endl;
    return false;
   }

   //Creating a raw board and filling it with board from .h so i can pass i in isValidMove()
   Square* rawBoard[8][8];
      for (int i = 0; i < 8; ++i){
          for (int j = 0; j < 8; ++j){
              rawBoard[i][j] = board[i][j].get();
          }
      }

   if(pieceToMove->isValidMove(startRow,startCol,endRow,endCol,rawBoard))
   {
      Piece* destinationPiece = board[endRow][endCol]->getPiece();

      if(destinationPiece != nullptr && destinationPiece->getColor() != pieceToMove->getColor())
      {
        board[endRow][endCol]->setPiece(nullptr);
      }
      board[endRow][endCol]->setPiece(std::move(board[startRow][startCol]->getPiecePtr()));
      board[startRow][startCol]->setPiece(nullptr); //clear original piece;


      return true;
   }else{
       std::cout << "Invalid move for the " << pieceToMove->getSymbol() << ". Please try again." << std::endl;
   }
}

void ChessBoard::mousePressEvent(QMouseEvent *event)
{
  qDebug() << "Mouse clicked at: " << event->pos();
  int squareSize = width() / 8;
  int col = event->pos().x() / squareSize;
  int row = event->pos().y() / squareSize;

  static bool selectingStart = true;
  static int startRow, startCol;

  if(!Piece::isWithingGrid(row,col)) return;

  if(!pieceSelected)
  {
      //first click : selects piece
      if(board[row][col]->getPiece() != nullptr && board[row][col]->getPiece()->getColor() == currentPlayer->get_color())
      {
          selectedSquare = {row,col};
          pieceSelected = true;
      }
  }else{
    //second click : try to move
    int startRow = selectedSquare.first;
    int startCol = selectedSquare.second;

    if(movePiece(*currentPlayer,startRow,startCol,row,col))
    {
     update();//auto call paintEvent() and repaint the board
     currentPlayer = (currentPlayer == &whitePlayer) ? &blackPlayer : &whitePlayer;
    }
     pieceSelected = false; // reset click state either way
  }
}


ChessBoard::~ChessBoard()
{
    delete ui;
}



