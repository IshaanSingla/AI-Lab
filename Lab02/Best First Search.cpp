#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

vector<vector<int>> GoalState = {{1,2,3},{4,5,6},{7,8,0}};
vector<vector<vector<int>>> Visited;

struct Node {
    stack<vector<vector<int>>> path;
    int heuristic;
    bool operator<(const Node &other) const {
        return heuristic > other.heuristic;
    }
};

int manhattan(const vector<vector<int>> &state) {
    int dist = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int val = state[i][j];
            if(val==0) continue;
            int goalRow = (val-1)/3;
            int goalCol = (val-1)%3;
            dist += abs(i-goalRow)+abs(j-goalCol);
        }
    }
    return dist;
}

bool findVisited(const vector<vector<int>> &s) {
    for(auto &visit : Visited) if(s == visit) return true;
    return false;
}

vector<Node> findMoves(Node &current) {
    vector<Node> moves;
    const vector<vector<int>> &state = current.path.top();
    int zeroRow=-1, zeroCol=-1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(state[i][j]==0){ zeroRow=i; zeroCol=j; break; }
        }
        if(zeroRow!=-1) break;
    }
    const vector<pair<int,int>> dirs={{1,0},{0,-1},{-1,0},{0,1}};
    for(auto &dir : dirs){
        int nr = zeroRow+dir.first;
        int nc = zeroCol+dir.second;
        if(nr>=0 && nr<3 && nc>=0 && nc<3){
            vector<vector<int>> newState = state;
            swap(newState[zeroRow][zeroCol], newState[nr][nc]);
            if(findVisited(newState)) continue;
            Node newNode;
            newNode.path = current.path;
            newNode.path.push(newState);
            newNode.heuristic = manhattan(newState);
            moves.push_back(newNode);
        }
    }
    return moves;
}

void PrintFinalStack(stack<vector<vector<int>>> s){
    vector<vector<vector<int>>> seq;
    while(!s.empty()){ seq.push_back(s.top()); s.pop(); }
    for(int i=seq.size()-1;i>=0;i--){
        for(auto &row : seq[i]){
            for(auto &val : row) cout << val << " ";
            cout << "\n";
        }
        cout << "-----\n";
    }
}

bool isSolvable(const vector<vector<int>> &state){
    vector<int> flat;
    for(auto &row : state) for(int val : row) if(val!=0) flat.push_back(val);
    int inv=0;
    for(int i=0;i<flat.size();i++){
        for(int j=i+1;j<flat.size();j++) if(flat[i]>flat[j]) inv++;
    }
    return inv%2==0;
}

int main(){
    vector<vector<int>> initialState={{1,2,3},{4,5,6},{7,0,8}};
    if(!isSolvable(initialState)){
        cout << "Goal state not reachable!\n";
        return 0;
    }

    stack<vector<vector<int>>> initialStack;
    initialStack.push(initialState);
    Node start; start.path = initialStack; start.heuristic = manhattan(initialState);

    priority_queue<Node> pq;
    pq.push(start);
    Visited.push_back(initialState);

    while(!pq.empty()){
        Node current = pq.top();
        pq.pop();
        if(current.path.top() == GoalState){
            cout << "Goal state reached!\n";
            PrintFinalStack(current.path);
            return 0;
        }
        vector<Node> moves = findMoves(current);
        for(auto &move : moves){
            pq.push(move);
            Visited.push_back(move.path.top());
        }
    }

    cout << "Goal state not reached!\n";
    return 0;
}
