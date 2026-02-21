#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// TODO: Build this solution using the approach used in the previous problem
// i.e., maintain the currentResult and push it into the final list of results in the Base case.
vector<vector<string>> getPalindromeParitionsUtil(int i, string &s) {
    if (i == s.length()) {
        return {{""}};
    }

    vector<vector<string>> result;

    for (int j = i; j < s.length(); j++) {
        if (isPalindrome(s, i, j)) {
            string current = s.substr(i, j - i + 1); // s[i ... j]
            vector<vector<string>> subResult = getPalindromeParitionsUtil(j + 1, s);

            for (vector<string> subPartition : subResult) {
                vector<string> currentParition;
                currentParition.push_back(current);

                for (string str : subPartition) {
                    currentParition.push_back(str);
                }

                result.push_back(currentParition);
            }

        }
    }
    return result;
}

vector<vector<string>> getPalindromeParitions(string s) {
    return getPalindromeParitionsUtil(0, s);
}

void getPalindromeParitionsApproach2Util(int i, string &s, vector<string> &curr, vector<vector<string>> &res) {
    if (i == s.length()) {
        res.push_back(curr);
        return;
    }

    for (int j = i; j < s.length(); j++) {
        if (isPalindrome(s, i, j)) {
            curr.push_back(s.substr(i, j - i + 1));
            getPalindromeParitionsApproach2Util(j + 1, s, curr, res);
            curr.pop_back();
        }
    }
}


vector<vector<string>> getPalindromeParitionsApproach2(string s) {
    vector<string> current;
    vector<vector<string>> result;

    getPalindromeParitionsApproach2Util(0, s, current, result);
    return result;
}

int main() {

    vector<vector<string>> result = getPalindromeParitionsApproach2("abcba");

    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
