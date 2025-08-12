#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct JugState {
    int jug1, jug2;
    string action;
};

int m, n, d;
queue<stack<JugState>> mainQueue;
stack<JugState> finalStack;
vector<pair<int,int>> Visited;

bool CheckGoalState(stack<JugState> &s)
{
    if (s.empty()) return false;
    JugState cur = s.top();
    return cur.jug1 == d || cur.jug2 == d;
}

bool find(const JugState &s)
{
    for (auto &v : Visited)
        if (v.first == s.jug1 && v.second == s.jug2) return true;
    return false;
}

vector<stack<JugState>> findMoves(stack<JugState> &s)
{
    vector<stack<JugState>> moves;
    JugState cur = s.top();

    vector<JugState> nextStates = {
        {m, cur.jug2, "Fill Jug1"},
        {cur.jug1, n, "Fill Jug2"},
        {0, cur.jug2, "Empty Jug1"},
        {cur.jug1, 0, "Empty Jug2"},
        {cur.jug1 - min(cur.jug1, n - cur.jug2), cur.jug2 + min(cur.jug1, n - cur.jug2), "Pour Jug1 -> Jug2"},
        {cur.jug1 + min(cur.jug2, m - cur.jug1), cur.jug2 - min(cur.jug2, m - cur.jug1), "Pour Jug2 -> Jug1"}
    };

    for (auto &next : nextStates)
    {
        if (find(next)) continue;
        stack<JugState> newStack(s);
        newStack.push(next);
        moves.push_back(newStack);
    }
    return moves;
}

void PrintFinalStack()
{
    stack<JugState> tempStack = finalStack;
    vector<JugState> path;
    while (!tempStack.empty())
    {
        path.push_back(tempStack.top());
        tempStack.pop();
    }

    cout << "Solution path:\n";
    for (int i = path.size() - 1; i >= 0; --i)
    {
        cout << "(" << path[i].jug1 << ", " << path[i].jug2 << ")";
        if (i != 0) cout << " -> " << path[i].action;
        cout << "\n";
    }
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    cout << "Enter capacity of Jug1: ";
    cin >> m;
    cout << "Enter capacity of Jug2: ";
    cin >> n;
    cout << "Enter target amount: ";
    cin >> d;

    if (d > max(m, n) || d % gcd(m, n) != 0)
    {
        cout << "No solution possible\n";
        return 0;
    }

    stack<JugState> initialStack;
    initialStack.push({0, 0, "Start"});
    mainQueue.push(initialStack);
    Visited.push_back({0, 0});

    while (!mainQueue.empty())
    {
        stack<JugState> stateStack(mainQueue.front());
        mainQueue.pop();

        if (CheckGoalState(stateStack))
        {
            finalStack = stateStack;
            PrintFinalStack();
            return 0;
        }

        vector<stack<JugState>> Moves = findMoves(stateStack);
        for (auto &move : Moves)
        {
            mainQueue.push(move);
            JugState top = move.top();
            Visited.push_back({top.jug1, top.jug2});
        }
    }

    cout << "Goal state not reached!\n";
    return 0;
}
