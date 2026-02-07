#include<bits/stdc++.h>
using namespace std;

vector<int> getPrevSmaller(vector<int> arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(i);
    }
    return result;
}

vector<int> getNextSmaller(vector<int> arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = n; // IMP
        } else {
            result[i] = s.top();
        }

        s.push(i);
    }
    return result;
}

// TC: O(n)
// AS: O(n)
vector<int> maximumOfMinimumsOfAllWindows(vector<int> arr) {

    vector<int> prevSmaller = getPrevSmaller(arr);
    vector<int> nextSmaller = getNextSmaller(arr);

    int n = arr.size();
    vector<int> result(n, INT_MIN);

    for (int i = 0; i < n; i++) {
        int window_size = nextSmaller[i] - prevSmaller[i] - 1;
        result[window_size - 1] = max(result[window_size - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        result[i] = max(result[i], result[i + 1]);
    }

    return result;
}

int main() {

    vector<int> result = maximumOfMinimumsOfAllWindows({10, 20, 30, 50, 10, 70, 30});
    for (int i : result) {
        cout << i << " ";
    }
}
