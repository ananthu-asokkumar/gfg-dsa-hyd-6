#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int countSubarraysWithEqual0sAnd1s(vector<int> arr) {

    unordered_map<int,int> sumFreq;
    sumFreq[0] = 1;

    int sum = 0;
    int result = 0;

    for (int i = 0; i < arr.size(); i++) {
        // if (arr[i] == 1) {
        //     sum++;
        // } else {
        //     sum--;
        // }
        sum += arr[i] == 1 ? +1 : -1;
        result += sumFreq[sum];

        sumFreq[sum]++;
    }

    return result;
}

int main() {

    cout << countSubarraysWithEqual0sAnd1s({1, 0, 0, 1, 0, 1, 1});
}