#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//Custom headers and forward declaration
#include "square.h"
#include "player.h"

//Qt & CPP includes
#include <QPainter>
#include <QMainWindow>
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
    void initializeWhitePieces();
    void initializeBlackPieces();
    bool movePiece(Player currentPlayer);
    void displayBoard();

protected:
    void paintEvent(QPaintEvent* event) override; //override the Qt method to paint what we want inside the widget.


private:
    Ui::ChessBoard *ui;
};
#endif // CHESSBOARD_H
