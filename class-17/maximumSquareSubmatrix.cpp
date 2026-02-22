#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(n^2)
int getMaximumSquareSubmatrixSum(vector<vector<int>> arr, int B) {

    int n = arr.size();
    
    vector<vector<int>> sums(n, vector<int> (n, 0));
    sums[0][0] = arr[0][0];

    for (int j = 1; j < n; j++) {
        sums[0][j] = sums[0][j - 1] + arr[0][j];
    }

    for (int i = 1; i < n; i++) {
        sums[i][0] = sums[i - 1][0] + arr[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            sums[i][j] = arr[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
        }
    }

    int result = INT_MIN;
    for (int i = B - 1; i < n; i++) {
        for (int j = B - 1; j < n; j++) {
            int currentSum = sums[i][j];
            if (j - B >= 0) {
                currentSum -= sums[i][j - B];
            }
            if (i - B >= 0) {
                currentSum -= sums[i - B][j];
            }
            if (i - B >= 0 && j - B >= 0) {
                currentSum += sums[i - B][j - B];
            }

            result = max(result, currentSum);
        }
    }

    return result;
}

int main() {

    cout << getMaximumSquareSubmatrixSum({
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 8, 6, 7, 3},
        {4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5}
    }, 3) << endl;
}
