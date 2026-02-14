#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n)
// AS: O(n)
void getUniqueSubsetsUtil(int i, vector<int> &arr, vector<int> &curr, vector<vector<int>> &res) {
    if (i == arr.size()) {
        res.push_back(curr);
        return;
    }

    int j = i + 1;
    while (j < arr.size() && arr[j] == arr[i]) {
        j++;
    }

    int freq = j - i;

    // for (int count = 0; count <= freq; count++) {

    //     for (int k = 0; k < count; k++) {
    //         curr.push_back(arr[i]);
    //     }

    //     getUniqueSubsetsUtil(j, arr, curr, res);

    //     for (int k = 0; k < count; k++) {
    //         curr.pop_back();
    //     }
    // }

    for (int count = 0; count <= freq; count++) {
        getUniqueSubsetsUtil(j, arr, curr, res);
        curr.push_back(arr[i]);
    }
    for (int count = 0; count <= freq; count++) {
        curr.pop_back();
    }

}

vector<vector<int>> getUniqueSubsets(vector<int> arr) {
    vector<vector<int>> res;
    vector<int> curr;

    sort(arr.begin(), arr.end());

    getUniqueSubsetsUtil(0, arr, curr, res);

    return res;
}

int main() {

    vector<vector<int>> res = getUniqueSubsets({1, 2, 3, 3});
    for (auto i : res){
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
