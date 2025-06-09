cmake_minimum_required(VERSION 3.16)

set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/forms     #NEED THIS BECAUSE ELSE AUTOUIC CANT FIND chessboard.ui ...
)

project(Chess VERSION 0.1 LANGUAGES CXX)

# Use Qt's automatic processing
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Collect sources
set(PROJECT_SOURCES
    forms/chessboard.ui
    include/bishop.h
    include/chessboard.h
    include/color.h
    include/king.h
    include/knight.h
    include/movementUtil.h
    include/pawn.h
    include/piece.h
    include/player.h
    include/queen.h
    include/rook.h
    include/square.h
    include/boardWidget.h
    src/bishop.cpp
    src/chessboard.cpp
    src/king.cpp
    src/knight.cpp
    src/main.cpp
    src/movementUtil.cpp
    src/pawn.cpp
    src/piece.cpp
    src/player.cpp
    src/queen.cpp
    src/rook.cpp
    src/square.cpp
    src/boardWidget.cpp
)

# Executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Chess
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_finalize_executable(Chess)
else()
    add_executable(Chess
        ${PROJECT_SOURCES}
    )
endif()

# Include directories
target_include_directories(Chess PRIVATE
    include
    forms
)
target_sources(Chess PRIVATE ${PROJECT_RESOURCES})
# Link Qt
target_link_libraries(Chess PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Resources
target_sources(Chess PRIVATE
    ChessRessources.qrc
)

# Install settings (optional)
install(TARGETS Chess
    BUNDLE DESTINATION .
    RUNTIME DESTINATION bin
)
