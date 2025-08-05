#include <iostream>
#include <vector>
#include <queue>        // Use queue for BFS
#include <stack>
using namespace std;

vector<vector<int>> GoalState = {{1,2,3},{4,5,6},{7,8,0}};
vector<vector<vector<int>>> Visited;
queue<stack<vector<vector<int>>>> mainQueue;  // BFS queue
stack<vector<vector<int>>> finalStack;

bool CheckGoalState(stack<vector<vector<int>>> &s)
{
    if (s.empty()) return false;
    const vector<vector<int>>& currentState = s.top();
    return currentState == GoalState;
}

bool find(const vector<vector<int>> &s)
{
    for(auto &visit : Visited)
    {
        if(s == visit)
        {
            // cout<<"Found the state" << "\n";
            return true;
        }
    }
    return false;
}

vector<stack<vector<vector<int>>>> findMoves(stack<vector<vector<int>>> &s)
{
    vector<stack<vector<vector<int>>>> moves;
    const vector<vector<int>>& currentState = s.top();
    int zeroRow = -1;
    int zeroCol = -1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (currentState[i][j] == 0)
            {
                zeroRow = i;
                zeroCol = j;
                break;
            }
        }
        if(zeroRow != -1) break;
    }

    const vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    for (auto &dir : directions)
    {
        const int newRow = zeroRow + dir.first;
        const int newCol = zeroCol + dir.second;

        if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3)
        {
            vector<vector<int>> newState = currentState;
            swap(newState[zeroRow][zeroCol], newState[newRow][newCol]);
            if(find(newState))
                continue;
            stack<vector<vector<int>>> newStack(s);
            newStack.push(newState);
            moves.push_back(newStack);
        }
    }

    return moves;
}

void PrintFinalStack()
{
    stack<vector<vector<int>>> tempStack = finalStack;
    cout << "Final Stack (Path from initial to goal):\n";
    vector<stack<vector<vector<int>>>> statesSequence;

    // Extract states from the stack to a vector for correct order printing
    while (!tempStack.empty())
    {
        statesSequence.push_back(tempStack);
        tempStack.pop();
    }

    // The vector currently holds stacks representing partial paths.
    // The top of the stack is the last state; we want to print from start to goal:
    // So we reverse and print the top element of each stack
    for (int i = statesSequence.size() - 1; i >= 0; --i)
    {
        vector<vector<int>> state = statesSequence[i].top();
        for (const auto &row : state)
        {
            for (const auto &elem : row)
            {
                cout << elem << " ";
            }
            cout << "\n";
        }
        cout << "-----\n";
    }
}

int main()
{
    vector<vector<int>> initialState = {{1,2,3}, {4,5,6}, {7,0,8}};
    stack<vector<vector<int>>> initialStack;
    initialStack.push(initialState);
    mainQueue.push(initialStack);
    Visited.push_back(initialState);

    while(!mainQueue.empty())
    {
        cout << "Queue size: " << mainQueue.size() << "\n";
        stack<vector<vector<int>>> stateStack(mainQueue.front());
        mainQueue.pop();

        if(CheckGoalState(stateStack))
        {
            cout << "Goal state reached!" << endl;
            finalStack = stateStack;
            PrintFinalStack();
            return 0;
        }

        vector<stack<vector<vector<int>>>> Moves = findMoves(stateStack);
        for (auto &move : Moves)
        {
            mainQueue.push(move);
            Visited.push_back(move.top());
        }
    }

    cout << "Goal state not reached!" << endl; 
    return 0;
}
