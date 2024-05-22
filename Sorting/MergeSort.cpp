/**
 * Author: omteja04
 * Created on: 21-05-2024 15:22:49
 * Description: MergeSort
 **/
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

void merge(int low, int mid, int high, int *arr) {
    int temp[high - low + 1];
    int ind = 0;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[ind++] = arr[left++];
        } else {
            temp[ind++] = arr[right++];
        }
    }
    while (left <= mid) {
        temp[ind++] = arr[left++];
    }
    while (right <= high) {
        temp[ind++] = arr[right++];
    }
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}
void mergeSort(int low, int high, int *arr) {
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    merge(low, mid, high, arr);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    cinArr(n, arr);
    mergeSort(0, n - 1, arr);
    coutArr(n, arr);
    return 0;
}