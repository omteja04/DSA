/**
 * Author: omteja04
 * Created on: 02-03-2024 18:12:41
 * Description: SquaresOfSortedArray
 **/
#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
vector<int> SquaresOfSortedArray(vector<int> &arr) {
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--) {
        if (abs(arr[left]) >= abs(arr[right])) {
            result[i] = arr[left] * arr[left];
            left++;
        } else {
            result[i] = arr[right] * arr[right];
            right--;
        }
    }
    return result;
}
int main() {
    vector<int> arr = {-4, -3, -1, 0, 8, 9, 10};
    vector<int> result = SquaresOfSortedArray(arr);
    for (auto &&i : result) {
        cout << i << " ";
    }

    return 0;
}