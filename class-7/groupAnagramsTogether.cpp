#include<bits/stdc++.h>
using namespace std;

string getHashKey(string s) {
    vector<int> freq(26, 0);
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    string key = "";

    for (int i = 0; i < 26; i++) {
        key += to_string(freq[i]);
        key += "#";
    }

    return key;
}

// TC: O(nm) where m is the length of the longst string.
// AS: O(nm)
// TODO:
// Create a map of {string, [list of indices]} and use them
// to create the output. AS should be optimized from O(nm) 
// to O(n).
vector<vector<string>> groupAnagrams(vector<string> arr) {
    int n = arr.size();
    unordered_map<string, vector<string>> freqStrToAnagrams;
    
    for (int i = 0; i < n; i++) {
        string key = getHashKey(arr[i]);
        freqStrToAnagrams[key].push_back(arr[i]);
    }

    vector<vector<string>> result;
    for (auto entry: freqStrToAnagrams) {
        result.push_back(entry.second);
    }
    return result;
}

int main() {

    vector<vector<string>> res = groupAnagrams({"cat", "god", "act", "dog", "tac"});
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
