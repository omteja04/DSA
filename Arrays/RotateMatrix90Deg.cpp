/**
 * Author: omteja04
 * Created on: 17-06-2024 14:49:33
 * Description: RotateMatrix90Deg
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

// Brute Force
/*
    ans[n][n]
    for(i 0 to n-1)
        for (j 0 to n-1)
            ans[j][n-1-i] = arr[i][j]


 */

// Better
// Transpose  + Reverse
void rotateMatrix(vector<vector<int>> &arr) {
    // Your code goes here
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (auto &row : arr) {
        reverse(row.begin(), row.end());
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    rotateMatrix(arr);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}