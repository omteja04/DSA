/**
 * Author: omteja04
 * Created on: 30-06-2024 12:18:51
 * Description: FrogJumpKJumps
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

int calculateUntil(int ind, int k, v32 &arr, v32 &dp) {
    if (ind == 0) {
        return 0;
    }

    if (dp[ind] != -1)
        return dp[ind];

    int finalCost = INT_MAX;

    for (int i = 1; i <= k; i++) {

        if ((ind - i) >= 0) {
            int currCost = calculateUntil(ind - i, k, arr, dp) + abs(arr[ind - i] - arr[ind]);
            finalCost = min(finalCost, currCost);
        }
    }
    return dp[ind] = finalCost;
}
int KJumps(int n, int k, v32 &arr) {
    v32 dp(n + 1, -1);
    return calculateUntil(n - 1, k, arr, dp);
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    cinArr(n, arr);
    cout << KJumps(n, k, arr);
    return 0;
}