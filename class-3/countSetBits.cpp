#include<bits/stdc++.h>
using namespace std;

int countSetBitsRec(int n) {
    if (n == 0) {
        return 0;
    }
    
    if ((n & 1) > 0) {
        return 1 + countSetBitsRec((n >> 1));
    }
    return countSetBitsRec(n >> 1);
}

// TC: O(length of the binary rep)
// AS: O(1)
int countSetBits(int n) {

    int result = 0;
    while (n > 0) {
        if ((n & 1) > 0) {
            result++;
        }
        n = (n >> 1);
    }
    return result;
}

// TC: O(number of set bits)
// AS: O(1)
int countSetBitsOptimal(int n) {

    int result = 0;
    while (n > 0) {
        n = (n & (n - 1));
        result++;
    }
    return result;
}

int main() {

    cout << countSetBits(10) << endl;
    cout << countSetBits(11) << endl;
    cout << countSetBits(15) << endl;

    cout << countSetBitsOptimal(10) << endl;
    cout << countSetBitsOptimal(11) << endl;
    cout << countSetBitsOptimal(15) << endl;
}
