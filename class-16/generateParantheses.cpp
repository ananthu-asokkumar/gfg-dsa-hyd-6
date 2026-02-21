#include<bits/stdc++.h>
using namespace std;

// T(n) = 2*T(n - 1) + c
// TC: O(2^n)
// AS: O(n)
void getAllValidParenthesesUtil(int n, int open, string &curr, vector<string> &result) {
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    // consider the opening bracket, if possible.
    if (open < n/2) {
        curr.push_back('(');
        getAllValidParenthesesUtil(n, open + 1, curr, result);
        curr.pop_back();
    }

    // consider the closing bracket, if possible.
    int close = curr.length() - open;
    if (close < open) {
        curr.push_back(')');
        getAllValidParenthesesUtil(n, open, curr, result);
        curr.pop_back();
    }
}

vector<string> getAllValidParentheses(int n) {
    string curr = "";
    vector<string> result;

    getAllValidParenthesesUtil(n, 0, curr, result);
    return result;
}

int main() {

    vector<string> result = getAllValidParentheses(4);
    for (string i : result) {
        cout << i << " ";
    }
}
