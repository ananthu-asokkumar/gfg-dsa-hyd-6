#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<int> &curr) {

    // col check
    for (int queenCol : curr) {
        if (queenCol == col) {
            return false;
        }
    }

    // diagonal check
    for (int i = 0; i < curr.size(); i++) {
        int prevRow = i + 1;
        int prevCol = curr[i];

        if (abs(row - prevRow) == abs(col - prevCol)) {
            return false;
        }
    }

    return true;
}

// T(n) = n*T(n - 1) + c
void nQueensUtil(int row, int n, vector<int> &curr, vector<vector<int>> &res) {
    if (row > n) {
        res.push_back(curr);
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col, n, curr)) {
            curr.push_back(col);
            nQueensUtil(row + 1, n, curr, res);
            curr.pop_back();
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<int> curr;
    vector<vector<int>> res;

    nQueensUtil(1, n, curr, res);
    return res;
}

int main() {

    vector<vector<int>> res = nQueens(4);

    for (auto i : res) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    vector<vector<int>> res2 = nQueens(3);

    for (auto i : res2) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    vector<vector<int>> res3 = nQueens(8);

    for (auto i : res3) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
