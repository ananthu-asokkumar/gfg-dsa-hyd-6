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
int maxAreaInHistogram(vector<int> heights) {
    vector<int> prevSmaller = getPrevSmaller(heights);
    vector<int> nextSmaller = getNextSmaller(heights);

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        maxArea = max(maxArea, width * heights[i]);
    }

    return maxArea;
}

int main() {

    cout << maxAreaInHistogram({6, 2, 5, 4, 5, 1, 6}) << endl;
}
