#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
void printNumbers1ToN(int n) {
    if (n <= 0) {
        return;
    }
    printNumbers1ToN(n - 1);
    cout << n << endl;
}

int main() {
    printNumbers1ToN(10);
}
