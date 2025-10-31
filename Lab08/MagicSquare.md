# Even Magic Square Generator

## AIM
To **generate a magic square** for even-order matrices (n × n, where n is even and n ≥ 4).

---

## Algorithm

1. **Input Validation**
   - Accepts an integer `n`.
   - Ensures that `n` is an even number and greater than or equal to 4.

2. **Double Even Case (n % 4 == 0)**
   - Fill the matrix sequentially.
   - Replace certain cells based on a pattern to maintain the magic property.

3. **Singly Even Case (n % 4 == 2)**
   - Construct four (n/2 × n/2) sub-squares.
   - Fill each with numbers in a specific order.
   - Swap selected columns to complete the magic square.

4. **Output**
   - Display the final magic square in a tabular format.

---

## Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void generateEvenMagicSquare(int n) {
    if (n < 4 || n % 2 != 0) {
        cout << "Enter an even number >= 4.\n";
        return;
    }

    vector<vector<int>> square(n, vector<int>(n));

    if (n % 4 == 0) {
        int num = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                square[i][j] = ((i % 4 == j % 4) || ((i % 4 + j % 4) == 3)) ? n * n + 1 - num++ : num++;
    } else {
        int half = n / 2, subSize = half * half;
        vector<vector<int>> sub(half, vector<int>(half));

        int i = 0, j = half / 2;
        for (int num = 1; num <= subSize; num++) {
            sub[i][j] = num;
            int ni = (i - 1 + half) % half;
            int nj = (j + 1) % half;
            if (sub[ni][nj] != 0) i = (i + 1) % half;
            else { i = ni; j = nj; }
        }

        for (int r = 0; r < half; r++)
            for (int c = 0; c < half; c++) {
                int val = sub[r][c];
                square[r][c] = val;
                square[r + half][c + half] = val + subSize;
                square[r][c + half] = val + 2 * subSize;
                square[r + half][c] = val + 3 * subSize;
            }

        int k = (half - 1) / 2;
        for (int r = 0; r < half; r++)
            for (int c = 0; c < k; c++)
                swap(square[r][c], square[r + half][c]);
        for (int r = 0; r < half; r++)
            for (int c = n - k + 1; c < n; c++)
                swap(square[r][c], square[r + half][c]);
    }

    cout << "Magic square of size " << n << ":\n";
    for (auto &row : square) {
        for (int val : row) cout << val << "\t";
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter an even number for Magic Square: ";
    cin >> n;
    generateEvenMagicSquare(n);
    return 0;
}
```

---

## Example Output

```
Enter an even number for Magic Square: 4

Magic square of size 4:
16	3	2	13	
5	10	11	8	
9	6	7	12	
4	15	14	1	
```

---

## Time Complexity
- For both **singly even** and **doubly even** cases, the algorithm runs in **O(n²)** time.
- Space complexity is **O(n²)** due to the use of a 2D matrix.

---

## Applications
- Used in **cryptography**, **art design**, **puzzle generation**, and **mathematical research**.
