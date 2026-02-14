#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &arr, int num) {

    // row check
    for (int k = 0; k < 9; k++) {
        if (arr[i][k] == num) {
            return false;
        }
    }

    // col check
    for (int k = 0; k < 9; k++) {
        if (arr[k][j] == num) {
            return false;
        }
    }

    // 3x3 submatrix check
    int row_start = i - i%3;
    int col_start = j - j%3;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (arr[row_start + r][col_start + c] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudokuUtil(int i, int j, vector<vector<int>> &arr) {
    if (i == 8 && j == 9) {
        return true;
    }

    if (j == 9) {
        i++;
        j = 0;
    }

    if (arr[i][j] != 0) {
        return solveSudokuUtil(i, j + 1, arr);
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(i, j, arr, num)) {
            arr[i][j] = num;
            if (solveSudokuUtil(i, j + 1, arr)) {
                return true;
            }
            arr[i][j] = 0;
        }
    }
    
    return false;
}

// Aymptotic Analysis: TODO
void solveSudoku(vector<vector<int>> &arr) {
    solveSudokuUtil(0, 0, arr);
}

int main() {

    vector<vector<int>> arr = {{3, 0, 6, 5, 7, 8, 4, 0, 0},
                               {5, 2, 0, 0, 0, 0, 0, 0, 0},
                               {0, 8, 7, 0, 0, 0, 0, 3, 1},
                               {0, 0, 3, 0, 1, 0, 0, 8, 0},
                               {9, 0, 0, 8, 6, 3, 0, 0, 5},
                               {0, 5, 0, 0, 9, 0, 6, 0, 0},
                               {1, 3, 0, 0, 0, 0, 2, 5, 0},
                               {0, 0, 0, 0, 0, 0, 0, 7, 4},
                               {0, 0, 5, 2, 8, 6, 3, 0, 0}};
    
    solveSudoku(arr);

    for (auto i : arr){
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
