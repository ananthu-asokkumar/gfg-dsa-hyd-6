#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int getSingleNumber(vector<int> arr) {

    vector<int> freq(32, 0);

    for (int i = 0; i < arr.size(); i++) {

        int num = arr[i];
        int pos = 0;

        while (pos < 32) {
            if ((num & 1) > 0) {
                freq[pos]++;
            }

            num = (num >> 1);
            pos++;
        }
    }

    int mul = 1;
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (freq[i] % 3 != 0) {
            result += mul;
        }
        mul *= 2;
    }

    return result;
}

int main() {
}
