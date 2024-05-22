/**
 * Author: omteja04
 * Created on: 26-02-2024 20:48:46
 * Description: InsertionSort
 **/

// ^ Very Adaptable & Stable Algorithm
//* Best Case TC        : O(n)      Already Sorted
//* Worst Case TC       : O(n^2)    Reversely Sorted
//* Space Complexity    : O(1)
//* UseCase             : When Array / Vector Size is Small

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
void insertionSort(int n, vector<int> &arr) {
    // Write your code here.

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    insertionSort(n, arr);
    for (int &i : arr)
        cout << i << " ";
    return 0;
}