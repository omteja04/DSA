/**
 * Author: omteja04
 * Created on: 03-03-2024 10:38:23
 * Description: findMinInROtatedArray
 **/

#include <bits/stdc++.h>
#define Boo cout << "Boo" << '\n'
using namespace std;
int findMin(int arr[], int n) {
    // complete the function here

    int start = 0;
    int end = n - 1;
    int mid;
    while (start < end) {
        mid = start + (end - start) / 2;
        if (arr[mid] >= arr[n - 1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return arr[start];
}
int findMin(int arr[], int n);

int main() {
    // Example usage
    int rotatedArray[] = {2, 3, 4, 5, 0, 1};
    // int rotatedArray[] = {33, 34, 35, 36, 37, 38, 39, 40, 41, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32};
    int size = sizeof(rotatedArray) / sizeof(rotatedArray[0]);

    int minElement = findMin(rotatedArray, size);

    cout << "The minimum element in the rotated sorted array is:" << minElement << endl;

    return 0;
}