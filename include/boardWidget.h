#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <memory>
#include "square.h"
#include "player.h"
#include "piece.h"
#include "square.h"

class BoardWidget : public QWidget
{
    Q_OBJECT

private:
    std::unique_ptr<Square> board[8][8];
    Player whitePlayer;
    Player blackPlayer;
    Player* currentPlayer;
    std::pair<int, int> selectedSquare; // to store first click (selection)
    bool pieceSelected = false;  // whether we're selecting or moving

public:
    BoardWidget(QWidget *parent = nullptr);
    void initializeBoardAndPieces();  //called in boardWidget constructor.
    bool movePiece(Player* currentPlayer, int startRow, int startCol, int endRow, int endCol);

protected:
    void paintEvent(QPaintEvent* event) override; //overrides the Qt method to paint what the content of board object inside the widget.
    void mousePressEvent(QMouseEvent* event) override; // the bridge between bool movePiece() and the GUI
};

#endif // BOARDWIDGET_H
