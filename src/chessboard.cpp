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
    , ui(new Ui::ChessBoard),
      boardWidget(new BoardWidget)

{
    ui->setupUi(this);
    setCentralWidget(boardWidget); //set our board as the central widget of chessboard which is the QMainWindow
    adjustSize();
    this->update(); //Qt actually handle the drawing and will call void paintEvent(QPaintEvent *event) on its own
    connect(ui->actionReset,&QAction::triggered,this,&ChessBoard::on_actionReset_triggered); // to reset the game by clicking on Reset Game in Menu
}

ChessBoard::~ChessBoard()
{
    delete ui;
}




void ChessBoard::on_actionReset_triggered()
{
  if(boardWidget)
  {
     boardWidget->initializeBoardAndPieces();
     update();
  }
}

