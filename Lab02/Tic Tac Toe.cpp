#include <iostream>
#include <vector>

#define Computer 1
#define Player2 2
using namespace std;

vector<vector<int>> Board = {{0,0,0},{0,0,0},{0,0,0}};



void PrintBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Board[i][j] << " ";
        }
        cout << endl;
    }
}


    

bool CheckWin(const int player) {
    for (int i = 0; i < 3; i++) {
        if (Board[i][0] == player && Board[i][1] == player && Board[i][2] == player) {
            return true;
        }
        if (Board[0][i] == player && Board[1][i] == player && Board[2][i] == player) {
            return true;
        }
    }
    if (Board[0][0] == player && Board[1][1] == player && Board[2][2] == player) {
        return true;
    }
    if (Board[0][2] == player && Board[1][1] == player && Board[2][0] == player) {
        return true;
    }
    return false;
}

pair<int, int> GetBestMove() {
    pair<int, int> bestMove = {-1, -1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board[i][j] == 0) {
                Board[i][j] = Computer;
                if (CheckWin(Computer)) {
                    bestMove = {i, j};
                    Board[i][j] = 0;
                    return bestMove;
                }
                Board[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board[i][j] == 0) {
                Board[i][j] = Player2;
                if (CheckWin(Player2)) {
                    bestMove = {i, j};
                    Board[i][j] = 0;
                    return bestMove;
                }
                Board[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 0) || (i == 2 && j == 2)) {
                if (Board[i][j] == 0) {
                    bestMove = {i, j};
                    return bestMove;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 2) || (i == 2 && j == 1)) {
                if (Board[i][j] == 0) {
                    bestMove = {i, j};
                    return bestMove;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board[i][j] == 0) {
                bestMove = {i, j};
                return bestMove;
            }
        }
    }
    return bestMove;
}

pair<int, int> GetMove(const int player) {
    int row, col;
    cout << "Player " << player << ", enter row and column (0-2): ";
    if (player == Computer) {
        row = GetBestMove().first;
        col = GetBestMove().second;
    }
    else {
        cin >> row >> col;
    }
    return {row, col};
}



int main() {
    int currentPlayer = Player2;
    while (true) {
        cout << "\n";
        PrintBoard();
        const pair<int, int> move = GetMove(currentPlayer);
        Board[move.first][move.second] = currentPlayer;
        if (CheckWin(currentPlayer)) {
            cout <<"\n";
            PrintBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if (currentPlayer == Computer) {
            currentPlayer = Player2;
        }
        else {
            currentPlayer = Computer;
        }
    }

    return 0;
}