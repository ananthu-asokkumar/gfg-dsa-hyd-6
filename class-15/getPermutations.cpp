#include<bits/stdc++.h>
using namespace std;

// TC - TODO
// AS - TODO
void getPermutationsUtil(int i, vector<int> &arr, vector<vector<int>> &res) {
    if (i == arr.size()) {
        res.push_back(arr);
        return;
    }

    for (int j = i; j < arr.size(); j++) {
        swap(arr[i], arr[j]);
        getPermutationsUtil(i + 1, arr, res);
        swap(arr[i], arr[j]);
    }
}

vector<vector<int>> getPermutations(vector<int> arr) {
    vector<vector<int>> res;
    getPermutationsUtil(0, arr, res);
    return res;
}

int main() {
    vector<vector<int>> res = getPermutations({1, 2, 3});
    for (auto i : res){
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
