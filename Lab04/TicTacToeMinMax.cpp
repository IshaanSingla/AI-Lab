#include<iostream>
#include<vector>
#include<limits>
using namespace std;

enum Players {
    None,
    Computer,
    Human
};

struct State {
    vector<vector<Players>> state;
};

long long leafCount = 0;

int checkGoal(const State& s) {
    const vector<vector<Players>> Board = s.state;
    for (int i = 0; i < 3; i++) {
        if (Board[i][0] == Board[i][1] && Board[i][1]== Board[i][2]) {
            if (Board[i][0] == None) return 0;
            return Board[i][0] == Computer?1:-1;
        }
        if (Board[0][i] ==Board[1][i] && Board[2][i] == Board[1][i]) {
            if (Board[0][i] == None) return 0;
            return Board[0][i] == Computer?1:-1;
        }
    }
    if (Board[0][0] == Board[1][1] && Board[2][2] == Board[1][1]) {
        if (Board[0][0] == None) return 0;
        return Board[0][0] == Computer?1:-1;
    }
    if (Board[0][2] == Board[1][1] && Board[2][0] == Board[1][1]) {
        if (Board[0][2] == None) return 0;
        return Board[0][2]== Computer?1:-1;
    }
    return 0;
}

bool isFull(const vector<vector<Players>> &Board) {
    for (auto &row : Board) {
        for (const int cell : row) {
            if (cell == None) return false;
        }
    }
    return true;
}

void printBoard(const vector<vector<Players>> &Board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            const char c = Board[i][j] == Computer ? 'X' : Board[i][j] == Human ? 'O' : '.';
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int minimax(State &s, const Players player) {
    const int winner = checkGoal(s);
    if (winner != 0) {
        leafCount++;
        return winner;
    }
    if (isFull(s.state)) {
        leafCount++;
        return 0;
    }

    if (player == Computer) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (s.state[i][j] == None) {
                    s.state[i][j] = Computer;
                    int score = minimax(s, Human);
                    s.state[i][j] = None;
                    bestScore = max(bestScore, score);
                }
            }
        }
        return bestScore;
    }

    int bestScore = numeric_limits<int>::max();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (s.state[i][j] == None) {
                s.state[i][j] = Human;
                int score = minimax(s, Computer);
                s.state[i][j] = None;
                bestScore = min(bestScore, score);
            }
        }
    }
    return bestScore;
}

pair<int,int> bestMove(State &s) {
    int bestScore = numeric_limits<int>::min();
    pair<int,int> move = {-1,-1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (s.state[i][j] == None) {
                s.state[i][j] = Computer;
                const int score = minimax(s, Human);
                s.state[i][j] = None;
                if (score > bestScore) {
                    bestScore = score;
                    move = {i,j};
                }
            }
        }
    }
    return move;
}

int main() {
    State start;
    start.state = vector<vector<Players>>(3, vector<Players>(3, None));
    Players player = Computer;

    while (true) {
        printBoard(start.state);

        if (checkGoal(start) == 1) {
            cout << "Computer wins!" << endl;
            break;
        }
        if (checkGoal(start) == -1) {
            cout << "You win!" << endl;
            break;
        }
        if (isFull(start.state)) {
            cout << "It's a draw!" << endl;
            break;
        }

        if (player == Human) {
            int r, c;
            cout << "Enter row and col (0-2): ";
            cin >> r >> c;
            if (r < 0 || r >= 3 || c < 0 || c >= 3 || start.state[r][c] != None) {
                cout << "Invalid move! Try again." << endl;
                continue;
            }
            start.state[r][c] = Human;
            player = Computer;
        } else {
            cout << "Computer is thinking..." << endl;
            leafCount = 0;
            const pair<int,int> mov = bestMove(start);
            cout << "Total leaf nodes explored = " << leafCount << endl;  // print leaf count
            const int r = mov.first;
            const int c = mov.second;
            start.state[r][c] = Computer;
            player = Human;
        }
    }
}
