#include<bits/stdc++.h>
using namespace std;

// TC: O(1)
// AS: O(1)
int unsetTheKthBit(int n, int k) {

    int mask = (~(1 << k));
    return (n & mask);
}

int main() {
    cout << unsetTheKthBit(45, 3) << endl;
    cout << unsetTheKthBit(37, 3) << endl;
}
