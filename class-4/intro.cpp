#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[5] = {50, 40, 30, 20, 10};

    cout << *arr << endl;

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " " << *(arr + i) << endl;
    }
}
