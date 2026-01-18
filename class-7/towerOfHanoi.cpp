#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n)
// AS: O(n)
int towerOfHanoi(int n, string A, string C, string B) {
    if (n == 0) {
        return 0;
    }

    int result = towerOfHanoi(n - 1, A, B, C);
    cout << "Move the " << n << "-th disk from " << A << " to " << C << endl;  
    result++; // To move nth disk from A to C.
    result += towerOfHanoi(n - 1, B, C, A);

    return result;
}

// TC: O(n)
// AS: O(n)
int towerOfHanoiOptimal(int n) {
    if (n == 0) {
        return 0;
    }
    return 2 * towerOfHanoiOptimal(n - 1) + 1;
}

int main() {

    cout << towerOfHanoi(2, "A", "C", "B") << endl;
    cout << towerOfHanoi(3, "A", "C", "B") << endl;

    cout << towerOfHanoiOptimal(2) << endl;
    cout << towerOfHanoiOptimal(3) << endl;
}
