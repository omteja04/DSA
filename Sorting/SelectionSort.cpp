/**
 * Author: omteja04
 * Created on: 21-05-2024 14:41:16
 * Description: SelectionSort
 **/

//! Selection Sort

//^ Selecting a minimum element in each iteration and placing it in its position
//& Time Complexity     : O(n^2)
//& Space Complexity    : O(1)
//& UseCase             : When Array / Vector Size is Small
//& It is a Stable Algorithm (Maintains relative order when 2 values are same)

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
void selectionSort(vector<int> &arr, int n) {
    // Write your code here.
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}
int main() {
    // Your code goes here
    vector<int> arr = {10, 9, 8, 1, 3, 2, 5};
    int n = arr.size();
    selectionSort(arr, n);
    for (int &i : arr)
        cout << i << " ";
    return 0;
}