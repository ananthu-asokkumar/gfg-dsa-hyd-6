#include<bits/stdc++.h>
using namespace std;

vector<int> getLowerUpperTriangleSum(vector<vector<int>> arr) {

    int n = arr.size();
    int lower = 0, upper = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            lower += arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            upper += arr[i][j];
        }
    }

    return {lower, upper};
}

int main() {
}
