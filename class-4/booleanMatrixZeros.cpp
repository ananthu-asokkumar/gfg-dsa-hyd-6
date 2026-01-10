#include<bits/stdc++.h>
using namespace std;

// TC: O(n*m)
// AS: O(1)
void booleanMatrixZeros(vector<vector<int>> &arr) {
    
    int n = arr.size();
    int m = arr[0].size();

    bool zerothRow = false;
    bool zerothCol = false;

    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            zerothRow = true;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            zerothCol = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0; // row bucket
                arr[0][j] = 0; // col bucket
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if (zerothRow) { // if the 0th row ORIGINALLY contains a zero.
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }

    if (zerothCol) { // if the 0th col ORIGINALLY contains a zero.
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }
}

int main() {

    vector<vector<int>> arr = {{1, 1, 1, 1, 1},
                               {1, 0, 1, 1, 1},
                               {1, 0, 1, 0, 1},
                               {1, 1, 1, 1, 1}};
    vector<vector<int>> arr2 = {{0, 1, 1, 1, 1},
                               {1, 1, 1, 1, 0},
                               {1, 1, 1, 1, 1},
                               {0, 1, 0, 1, 1},
                               {1, 1, 1, 1, 1}};

    booleanMatrixZeros(arr);
    booleanMatrixZeros(arr2);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < arr2.size(); i++) {
        for (int j = 0; j < arr2[i].size(); j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}
