#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
bool subarrayWithZeroSum(vector<int> arr) {

    unordered_set<int> visited;
    
    int sum = 0;
    visited.insert(sum);

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        
        // checking if sum is there in the visited set.
        if (visited.find(sum) != visited.end()) {
            return true;
        }

        visited.insert(sum);
    }

    return false;
}

int main() {
    cout << subarrayWithZeroSum({4, 2, -3, 1, 6}) << endl;
    cout << subarrayWithZeroSum({4, 2, -6, 1, 6}) << endl;
    cout << subarrayWithZeroSum({4, 2, 3, 1, 6}) << endl;
    cout << subarrayWithZeroSum({4, 2, 0, 1, 6}) << endl;
    cout << subarrayWithZeroSum({4, 2, -6}) << endl;
}