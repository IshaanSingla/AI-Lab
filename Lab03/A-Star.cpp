#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

struct Node {
    int row, col;
    int g, h;
    Node* parent;
    bool operator<(const Node &other) const {
        return (g+h) > (other.g + other.h);
    }
};

int manhattan(int r1, int c1, int r2, int c2){
    return abs(r1 - r2) + abs(c1 - c2);
}

bool isValid(int r, int c, int rows, int cols, const vector<vector<int>> &grid){
    return r>=0 && r<rows && c>=0 && c<cols && grid[r][c]==0;
}

stack<pair<int,int>> reconstructPath(Node* node){
    stack<pair<int,int>> path;
    while(node){
        path.push({node->row, node->col});
        node = node->parent;
    }
    return path;
}

void printPath(stack<pair<int,int>> path){
    while(!path.empty()){
        auto p = path.top(); path.pop();
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n";
}

bool isSolvable(const vector<vector<int>> &grid, pair<int,int> start, pair<int,int> goal){
    int rows = grid.size();
    int cols = grid[0].size();
    if(grid[start.first][start.second]==1 || grid[goal.first][goal.second]==1) return false;
    return true;
}

void AStar(vector<vector<int>> &grid, pair<int,int> start, pair<int,int> goal){
    if(!isSolvable(grid,start,goal)){
        cout << "No path possible: start or goal blocked!\n";
        return;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    priority_queue<Node> open;
    vector<vector<bool>> visited(rows, vector<bool>(cols,false));

    Node* startNode = new Node{start.first, start.second, 0, manhattan(start.first,start.second,goal.first,goal.second), nullptr};
    open.push(*startNode);

    while(!open.empty()){
        Node current = open.top();
        open.pop();

        if(visited[current.row][current.col]) continue;
        visited[current.row][current.col] = true;

        if(current.row == goal.first && current.col == goal.second){
            stack<pair<int,int>> path = reconstructPath(&current);
            cout << "Path found:\n";
            printPath(path);
            return;
        }

        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto &dir : directions){
            int nr = current.row + dir.first;
            int nc = current.col + dir.second;
            if(isValid(nr,nc,rows,cols,grid) && !visited[nr][nc]){
                Node* neighbor = new Node{nr,nc,current.g+1,manhattan(nr,nc,goal.first,goal.second), new Node(current)};
                open.push(*neighbor);
            }
        }
    }

    cout << "No path found: goal not reachable!\n";
}

int main(){
    vector<vector<int>> grid = {
        {0,0,0,0,0},
        {0,1,1,0,0},
        {0,0,0,1,0},
        {0,1,0,0,0},
        {0,0,0,1,0}
    };
    pair<int,int> start = {0,0};
    pair<int,int> goal = {4,4};

    AStar(grid,start,goal);

    return 0;
}
