#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int longestSubstringWithDistinctChars(string s) {

    int n = s.length();
    vector<bool> isPresent(26, false);

    int i = 0, j = 0;

    int result = 0;
    while (j < n) {
        if (!isPresent[s[j] - 'a']) {
            isPresent[s[j] - 'a'] = true;
            result = max(result, j - i + 1);
        } else {
            while (s[i] != s[j]) {
                isPresent[s[i] - 'a'] = false;
                i++;
            }
            i++;
        }
        j++;
    }

    return result;
}

int main() {
    cout << longestSubstringWithDistinctChars("geeksforgeeks") << endl;
    cout << longestSubstringWithDistinctChars("aaa") << endl;
    cout << longestSubstringWithDistinctChars("abcdefdgh") << endl;
}
