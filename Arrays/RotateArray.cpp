/**
 * Author: omteja04
 * Created on: 28-05-2024 15:16:50
 * Description: LeftRotateArray
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

void leftRotateArrayBruteForce(int n, int k, vector<int> &arr) {

    //^ Brute Force
    if (n == 0 || k % n == 0)
        return;

    k %= n;
    vector<int> temp(arr.begin(), arr.begin() + k);
    // Each Element moves left by k places
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }
    // the first k elements will start from n - k;
    for (int i = n - k; i < n; i++) {
        arr[i] = temp[i - (n - k)];
    }

    // TC - O(k) + O(n - k) + O(d) -> O(n+d)
    // SC - O(d)
}

void leftRotateArrayOptimal(int n, int k, vector<int> &arr) {
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
    // TC - O(d) + O(n - d) + O(n) -> O(2n)
    // SC - O(1)
}
void rightRotateArrayOptimal(int n, int k, vector<int> &arr) {
    // 1 2 3 4 5
    // Reverse upto n-k
    // 3 2 1 4 5
    // Reverse last k
    // 3 2 1 5 4
    // Reverse whole array
    // 4 5 1 2 3

    reverse(arr.begin(), arr.end() - k);
    reverse(arr.end() - k, arr.end());
    reverse(arr.begin(), arr.end());
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    cinArr(n, arr);

    // Left rotate the array
    leftRotateArrayOptimal(n, k, arr);
    // Print the leftRotated array
    coutArr(n, arr);
    cout << '\n';

    // Right rotate the array
    rightRotateArrayOptimal(n, k, arr);

    // Print the rightRotated array
    coutArr(n, arr);
    cout << '\n';

    return 0;
}