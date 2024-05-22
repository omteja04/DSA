/**
 * Author: omteja04
 * Created on: 22-05-2024 16:37:16
 * Description: QuickSort
 **/

// Pivot Element

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
typedef long long ll;
#define cinArr(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
#define coutArr(n, arr)        \
    for (ll i = 0; i < n; i++) \
    cout << arr[i] << ' '

int findPartition(int low, int high, int *arr) {
    int pivotIndex = low;
    int i = low;
    int j = high;
    while (i < j) {
        while (arr[i] <= arr[pivotIndex] && i <= high) {
            i++;
        }
        while (arr[j] > arr[pivotIndex] && j >= low) {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[pivotIndex]);
    return j;
}
void quickSort(int low, int high, int *arr) {
    if (low < high) {
        int partition = findPartition(low, high, arr);
        quickSort(low, partition - 1, arr);
        quickSort(partition + 1, high, arr);
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    cinArr(n, arr);
    quickSort(0, n - 1, arr);
    coutArr(n, arr);
    return 0;
}