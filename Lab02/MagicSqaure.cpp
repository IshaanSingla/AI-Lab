#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMagicSquare(int n) {
    vector<vector<int>> magic(n, vector<int>(n, 0));

    int num = 1;
    int i = 0, j = n / 2;

    while(num <= n*n){
        magic[i][j] = num;
        num++;
        int newi = (i-1+n) % n;
        int newj = (j+1) % n;
        if(magic[newi][newj] != 0){
            i = (i+1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }

    return magic;
}

void printMagicSquare(const vector<vector<int>> &magic) {
    int n = magic.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << magic[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter odd size of magic square: ";
    cin >> n;
    if(n % 2 == 0){
        cout << "Only odd-sized magic squares are supported.\n";
        return 0;
    }

    vector<vector<int>> magic = generateMagicSquare(n);
    cout << "Magic Square of size " << n << ":\n";
    printMagicSquare(magic);

    return 0;
}
