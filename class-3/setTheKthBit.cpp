#include<bits/stdc++.h>
using namespace std;

// TC: O(1)
// AS: O(1)
int setTheKthBit(int n, int k) {

    int mask = (1 << k);
    return (n | mask);
}

int main() {
    cout << setTheKthBit(45, 1) << endl;
    cout << setTheKthBit(47, 1) << endl;
}
