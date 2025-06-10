#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//Custom headers and forward declaration
#include "square.h"
#include "player.h"
#include "boardWidget.h"

//Qt & CPP includes
#include <QPainter>
#include <QMainWindow>
#include <QPixmap>
#include <QMouseEvent>
#include <memory>


QT_BEGIN_NAMESPACE
namespace Ui { class ChessBoard; }
QT_END_NAMESPACE

class ChessBoard : public QMainWindow
{
    Q_OBJECT

private:
    BoardWidget* boardWidget;

public:
    ChessBoard(QWidget *parent = nullptr);
    ~ChessBoard();


private slots:
    void on_actionReset_triggered();

private:
    Ui::ChessBoard *ui;
};
#endif // CHESSBOARD_H
