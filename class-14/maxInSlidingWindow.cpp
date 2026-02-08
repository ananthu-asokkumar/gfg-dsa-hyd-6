#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> getMaxInSlidingWindow(vector<int> arr, int k) {

    int n = arr.size();
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);

    for (int i = k; i < n; i++) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        res.push_back(arr[dq.front()]);
    }

    return res;
}

int main() {

    vector<int> res = getMaxInSlidingWindow({1, 2, 3, 1, 4, 5, 2, 3, 2}, 3);
    for (int i : res) {
        cout << i << " ";
    }
}
