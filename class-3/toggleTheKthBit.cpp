#include<bits/stdc++.h>
using namespace std;

// TC: O(1)
// AS: O(1)
int toggleTheKthBit(int n, int k) {

    int mask = (1 << k);
    return (n ^ mask);
}

int main() {
    cout << toggleTheKthBit(45, 3) << endl;
    cout << toggleTheKthBit(37, 3) << endl;
}
