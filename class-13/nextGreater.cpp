#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> nextGreater(vector<int> arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] >= s.top()) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(arr[i]);
    }
    return result;
}

int main() {

    vector<int> result = nextGreater({6, 8, 0, 1, 3});
    vector<int> result1 = nextGreater({6, 8, 0, 3, 1});

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : result1) {
        cout << i << " ";
    }
    cout << endl;
}
