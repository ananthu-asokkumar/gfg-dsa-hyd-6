#include<bits/stdc++.h>
using namespace std;

// TODO: Rotate 90 degrees clockwise without using extra space.

// TC: O(n^2)
// AS: O(1)
void rotateBy90Degrees(vector<vector<int>> &arr) {
    int n = arr.size();

    // Step-1: Reverse the rows.
    for (int i = 0; i < n; i++) {
        int low = 0, high = n - 1;
        while (low < high) {
            swap(arr[i][low], arr[i][high]);
            low++;
            high--;
        }
    }

    // Step-2: Swap the lower triangle with the upper triangle.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main() {

    vector<vector<int>> arr = {{0, 1, 2},
                                {3, 4, 5},
                                {6, 7, 8}};
    
    rotateBy90Degrees(arr);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
