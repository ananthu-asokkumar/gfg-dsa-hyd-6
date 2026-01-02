#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int getSingleNumber(vector<int> arr) {

    int result = 0;
    for (int i = 0; i < arr.size(); i++) {
        result = (result ^ arr[i]);
    }

    return result;
}

int main() {

    cout << getSingleNumber({1, 2, 1, 5, 5}) << endl;
    cout << getSingleNumber({2, 30, 2, 15, 20, 30, 15}) << endl;
}
