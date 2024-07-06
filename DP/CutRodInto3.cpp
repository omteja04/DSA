/**
 * Author: omteja04
 * Created on: 06-07-2024 19:55:59
 * Description: CutRodInto3
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
const int MOD = 1000000007;
typedef vector<int> v32;

// ! Returns TLE
int leviRecursion(int n, int x, int y, int z) {
    // Base Case
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return INT_MIN;
    }
    int a = leviRecursion(n - x, x, y, z) + 1; // Adding One to count the current segment
    int b = leviRecursion(n - y, x, y, z) + 1;
    int c = leviRecursion(n - z, x, y, z) + 1;

    return max({a, b, c});
}

int leviMemoization(int n, int x, int y, int z, v32 &dp) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return INT_MIN;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int a = leviMemoization(n - x, x, y, z, dp) + 1; // Adding One to count the current segment
    int b = leviMemoization(n - y, x, y, z, dp) + 1;
    int c = leviMemoization(n - z, x, y, z, dp) + 1;

    return dp[n] = max({a, b, c});
}

int leviTabulation(int n, int x, int y, int z) {
    v32 dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i - x >= 0 && dp[i - x] != -1)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0 && dp[i - y] != -1)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0 && dp[i - z] != -1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    return dp[n];
}
int main() {
    int n;
    int x, y, z;
    cin >> n >> x >> y >> z;
    // int ans = leviRecursion(n, x, y, z);
    // v32 dp(n + 1, -1);
    // int ans = leviMemoization(n, x, y, z, dp);
    int ans = leviTabulation(n, x, y, z);
    if (ans < 0)
        cout << 0;
    else
        cout << ans;
    return 0;
}