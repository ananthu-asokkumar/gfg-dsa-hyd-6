#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> firstNegativeInEachWindow(vector<int> arr, int k) {

    queue<int> q;
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            q.push(i);
        }
    }

    if (q.empty()) {
        res.push_back(0);
    } else {
        res.push_back(arr[q.front()]);
    }

    for (int i = k; i < n; i++) {
        if (arr[i] < 0) {
            q.push(i);
        }
        if (!q.empty() && q.front() <= i - k) {
            q.pop();
        }

        if (q.empty()) {
            res.push_back(0);
        } else {
            res.push_back(arr[q.front()]);
        }
    }

    return res;
}

int main() {

    vector<int> res = firstNegativeInEachWindow({12, -1, -7, 8, -15, 30, 16, 28}, 3);
    for (int i : res) {
        cout << i << " ";
    }
}
