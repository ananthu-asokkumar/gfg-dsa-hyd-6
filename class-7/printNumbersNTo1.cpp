#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1) - since its tail recursive.
void printNumbersNTo1(int n) {
    if (n <= 0) {
        return;
    }
    cout << n << endl;
    printNumbersNTo1(n - 1);
}

int main() {
    printNumbersNTo1(10);
}
