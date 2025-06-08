#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//Custom headers and forward declaration
#include "square.h"
#include "player.h"

//Qt & CPP includes
#include <QPainter>
#include <QMainWindow>
#include <QPixmap>
#include <memory>


QT_BEGIN_NAMESPACE
namespace Ui { class ChessBoard; }
QT_END_NAMESPACE

class ChessBoard : public QMainWindow
{
    Q_OBJECT

private:
    std::unique_ptr<Square> board[8][8];
public:
    ChessBoard(QWidget *parent = nullptr);
    ~ChessBoard();

    //methods
    void initializeBoardAndPieces(); //called in chessboard constructor.
    void initializeWhitePieces();//inside initializeBoardAndPieces()
    void initializeBlackPieces();//inside initializeBoardAndPieces()
    bool movePiece(Player currentPlayer,int startRow, int startCol, int endRow, int endCol);

protected:
    void paintEvent(QPaintEvent* event) override; //overrides the Qt method to paint what the content of board object inside the widget.
    void mousePressEvent(QMouseEvent* event) override; // the bridge between bool movePiece() and the GUI


private:
    Ui::ChessBoard *ui;
};
#endif // CHESSBOARD_H
