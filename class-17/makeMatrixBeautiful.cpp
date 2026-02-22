#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(1)
int makeMatrixBeautiful(vector<vector<int>> arr) {

    int n = arr.size();
    int maxx = 0, totalSum = 0;

    for (int i = 0; i < n; i++) {
        int currentRow = 0;
        for (int j = 0; j < n; j++) {
            currentRow += arr[i][j];
        }
        maxx = max(maxx, currentRow);
        totalSum += currentRow;
    }

    for (int j = 0; j < n; j++) {
        int currentCol = 0;
        for (int i = 0; i < n; i++) {
            currentCol += arr[i][j];
        }
        maxx = max(maxx, currentCol);
    }

    return maxx*n - totalSum;
}

int main() {

    cout << makeMatrixBeautiful({
        {1, 6, 4},
        {2, 5, 1},
        {3, 9, 2}
    });
}
