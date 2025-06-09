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
    BoardWidget* boardWidget = new BoardWidget(this);
    setCentralWidget(boardWidget); //set our board as the central widget of chessboard which is the QMainWindow
    this->update(); //Qt actually handle the drawing and will call void paintEvent(QPaintEvent *event) on its own

}

ChessBoard::~ChessBoard()
{
    delete ui;
}



