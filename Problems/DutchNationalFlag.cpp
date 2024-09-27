/**
 * Author: omteja04
 * Created on: 03-03-2024 10:37:00
 * Description: DutchNationalFlag
 **/

#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
// This Works Only when there are 3 unique type of elements
void DutchNationalFlag(int arr[], int n) {

    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (mid <= high) {
        switch (arr[mid]) {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[high], arr[mid]);
            high--;
            break;
        }
    }
}
// cSpell:disable
// https : // www.geeksforgeeks.org/problems/three-way-partitioning/1
int main() {
    // Your code goes here
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Before" << '\n';
    printArray(arr, n);
    DutchNationalFlag(arr, n);
    cout << "\nAfter" << '\n';
    printArray(arr, n);

    return 0;
}