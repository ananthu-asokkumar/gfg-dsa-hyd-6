#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int getDistinctInSortedArray(vector<int> &arr) {

    int n = arr.size();

    int i = 0; // responsible for fetching the unique elements.
    int j = 0; // responsible for telling the position for the next unique element.

    while (i < n) {

        arr[j] = arr[i];
        j++;

        i++;
        while (i < n && arr[i] == arr[i - 1]) {
            i++;
        }
    }

    return j;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 3, 5, 5, 6, 6};
    int size = getDistinctInSortedArray(arr);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
