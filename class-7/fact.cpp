#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n) 
int fact(int n) {
    if (n <= 0) {
        return 1;
    }
    return n * fact(n - 1);
}

void factUtil(int n, int &res) {
    if (n <= 0) {
        return;
    }
    res *= n;
    factUtil(n - 1, res);
}

// TC: O(n)
// AS: O(1)
int factTailRec(int n) {
    int res = 1;
    factUtil(n, res);
    return res;
}

int main() {
    cout << fact(5);
}
