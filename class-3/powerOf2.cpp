#include<bits/stdc++.h>
using namespace std;

// TC: O(1)
// AS: O(1)
int checkPowerOf2(int n) {
    if (n == 0) {
        return false;
    }
    return ((n & (n - 1)) == 0);
}

int main() {
    cout << checkPowerOf2(45) << endl;
    cout << checkPowerOf2(32) << endl;
}
