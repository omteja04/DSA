/**
 * Author: omteja04
 * Created on: 01-07-2024 22:13:10
 * Description: HouseRobber
 **/

// https://leetcode.com/problems/house-robber/

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

int tabulation(int n, v32 &arr, v32 &dp) {
    dp[0] = arr[0];
    // bool negative = 0;
    for (int i = 1; i < n; i++) {

        int pick = arr[i];
        if (i > 1) {
            pick += dp[i - 2];
        }
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }

    return dp[n - 1];
}
int memoization(int ind, v32 &arr, v32 &dp) {
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    return dp[ind] = max(arr[ind] + memoization(ind - 2, arr, dp), memoization(ind - 1, arr, dp));
}
int levi(int n, vector<int> &arr) {
    // vector<int> dp(n, 0);
    // return tabulation(n, arr, dp);
    // return memoization(n - 1, arr, dp);

    int past = 0;
    int just = arr[0];
    for (int i = 1; i < n; i++) {
        int take = arr[i];
        if (i > 1) {
            take += past;
        }
        int notTake = just;

        int curr = max(take, notTake);
        past = just;
        just = curr;
    }
    return just;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    cout << levi(n, arr);
    return 0;
}