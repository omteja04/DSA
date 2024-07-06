/**
 * Author: omteja04
 * Created on: 30-06-2024 10:43:26
 * Description: FrogJump
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
typedef vector<int> v32;

int memoization(int ind, v32 &arr, v32 &dp) {
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int left = memoization(ind - 1, arr, dp) + abs(arr[ind - 1] - arr[ind]);
    int right = INT_MAX;
    if (ind > 1) {
        right = memoization(ind - 2, arr, dp) + abs(arr[ind - 2] - arr[ind]);
    }
    return dp[ind] = min(left, right);
}

int tabulation(int n, vector<int> &arr, vector<int> &dp) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int left = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if (i > 1) {
            right = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n];
}

int frogJump(int n, vector<int> &arr) {

    int a = 0;
    int b = 0;

    for (int i = 1; i < n; i++) {
        int first = b + abs(arr[i] - arr[i - 1]);
        int second = INT_MAX;

        if (i > 1) {
            second = a + abs(arr[i - 2] - arr[i]);
        }

        int cur = min(first, second);
        a = b;
        b = cur;
    }

    return b;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    cout << frogJump(n, arr);
    return 0;
}