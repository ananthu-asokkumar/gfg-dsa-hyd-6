#include<bits/stdc++.h>
using namespace std;

// TC: O(n*m)
// AS: O(1)
vector<int> getSpiralTraversal(vector<vector<int>> arr) {

    int n = arr.size(), m = arr[0].size();

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    vector<int> result;

    while (result.size() < n*m) {
        // right
        for (int j = left; j <= right; j++) {
            result.push_back(arr[top][j]);
        }

        // down
        for (int i = top + 1; i <= bottom; i++) {
            result.push_back(arr[i][right]);
        }

        // left
        if (bottom > top) {
            for (int j = right - 1; j >= left; j--) {
                result.push_back(arr[bottom][j]);
            }
        }

        // up
        if (left < right) {
            for (int i = bottom - 1; i >= top + 1; i--) {
                result.push_back(arr[i][left]);
            }
        }

        top++, bottom--, left++, right--;
    }

    return result;
}

int main() {

    vector<int> res1 = getSpiralTraversal({
                                            {1, 2, 3, 4, 5},
                                            {6, 7, 8, 9, 10},
                                            {11, 12, 13, 14, 15}
                                        });
    
    for (auto i : res1) {
        cout << i << " ";
    }
}
