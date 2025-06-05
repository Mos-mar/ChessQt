TEMPLATE = app
TARGET = Chess
QT += widgets

INCLUDEPATH += include #Add this line so compiler knows to look in include/
INCLUDEPATH += forms #if i add .hpp in forms who knows...

SOURCES += \
    src/bishop.cpp \
    src/chessgame.cpp \
    src/king.cpp \
    src/knight.cpp \
    src/movementUtil.cpp \
    src/pawn.cpp \
    src/player.cpp \
    src/queen.cpp \
    src/rook.cpp \
    src/square.cpp \
    src/main.cpp \
    src/chessboard.cpp \
    src/piece.cpp \

HEADERS += \
    include/bishop.h \
    include/chessboard.h \
    include/chessgame.h \
    include/color.h \
    include/king.h \
    include/knight.h \
    include/movementUtil.h \
    include/pawn.h \
    include/piece.h \
    include/player.h \
    include/queen.h \
    include/rook.h \
    include/square.h

FORMS += \
    forms/chessboard.ui

DISTFILES += images\
    images/black-bishop.png \
    images/black-king.png \
    images/black-knight.png \
    images/black-pawn.png \
    images/black-queen.png \
    images/black-rook.png \
    images/white-bishop.png \
    images/white-king.png \
    images/white-knight.png \
    images/white-pawn.png \
    images/white-queen.png \
    images/white-rook.png

