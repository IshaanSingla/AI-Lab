cmake_minimum_required(VERSION 4.0)
project(AI_Lab)

set(CMAKE_CXX_STANDARD 23)

add_executable(8TileProblemDFS
        "Lab01/8 tile problem DFS.cpp")
add_executable(BestFirstSearch "Lab02/Best First Search.cpp")
add_executable(Jugs "Lab02/Jugs.cpp")
add_executable(MagicSquare "Lab02/MagicSqaure.cpp")
add_executable(TicTacToe "Lab02/Tic Tac Toe.cpp")
add_executable(AStar "Lab03/A-Star.cpp")
add_executable(8TileProblemBFS "Lab01/8 tile problem BFS.cpp")
add_executable(TicTacToeMinMax "Lab04/TicTacToeMinMax.cpp")
add_executable(TicTacToeAlphaBeta Lab04/TicTacToeAlphaBeta.cpp)
