/**
 * Author: omteja04
 * Created on: 03-03-2024 10:38:39
 * Description: BubbleSort
 **/

//! Bubble Sort

//^ Selecting a minimum element in each iteration and placing it in its position
//* Best Case TC        : O(n)      Already Sorted
//* Worst Case TC       : O(n^2)    Reversely Sorted
//* Space Complexity    : O(1)
//* UseCase             : When Array / Vector Size is Small
//* It is a Stable Algorithm (Maintains relative order when 2 values are same)
#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
void BubbleSort(vector<int> &arr, int n) {
    // Write your code here.
    for (int i = 0; i < n - 1; i++) {
        bool didSwap = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (didSwap == false)
            break;
    }
}
int main() {
    // Your code goes here
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();
    BubbleSort(arr, n);
    for (int &i : arr)
        cout << i << " ";
    return 0;
}