#include<bits/stdc++.h>
using namespace std;

bool isMatch(char op, char cl) {
    return
        (op == '(' && cl == ')') ||
        (op == '[' && cl == ']') ||
        (op == '{' && cl == '}');
}

// TC: O(n)
// AS: O(n)
bool checkBalanced(string s) {

    stack<char> opens;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            opens.push(s[i]);
        } else {
            if (opens.empty() || !isMatch(opens.top(), s[i])) {
                return false;
            }
            opens.pop();
        }
    }

    return opens.size() == 0;
}

int main() {

    cout << checkBalanced("{([])}") << endl;
    cout << checkBalanced("{([])}[]") << endl;
    cout << checkBalanced("{}[]()") << endl;
    cout << checkBalanced("{([)]}") << endl;
    cout << checkBalanced("{([])") << endl;
    cout << checkBalanced("{(])}") << endl;
    cout << checkBalanced("(()") << endl;
    cout << checkBalanced("())") << endl;
}
