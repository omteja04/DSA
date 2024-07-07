/**
 * Author: omteja04
 * Created on: 07-07-2024 14:32:17
 * Description: CountDe-Arrangements
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
#define cinArr(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
#define coutArr(n, arr)        \
    for (ll i = 0; i < n; i++) \
    cout << arr[i] << ' '

typedef long long ll;
typedef vector<int> v32;
const int MOD = 1000000007;

// ! Return TLE
ll leviRecursion(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    ll ans = ((n - 1) % MOD) * ((leviRecursion(n - 1) % MOD) + (leviRecursion(n - 2) % MOD));
    ans %= MOD;
    return ans;
}

ll leviMemoization(int n, v32 &dp) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    ll ans = ((n - 1) % MOD) * ((leviMemoization(n - 1, dp) % MOD) + (leviMemoization(n - 2, dp) % MOD));
    ans %= MOD;
    return dp[n] = ans;
}

ll leviTabulation(int n) {
    v32 dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        ll a = dp[i - 1] % MOD;
        ll b = dp[i - 2] % MOD;
        ll ab = (a + b) % MOD;
        ll ans = ((i - 1) * ab) % MOD;
        dp[i] = ans;
    }
    return dp[n];
}

ll leviSpaceOptimization(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    ll a = 0;
    ll b = 1;
    for (int i = 3; i <= n; i++) {
        ll c = (((i - 1) % MOD) * ((a + b) % MOD)) % MOD;
        a = b;
        b = c;
    }
    return b;
}
int main() {
    int n;
    cin >> n;
    // ll ans = leviRecursion(n);
    // v32 dp(n, -1);
    // ll ans = leviMemoization(n + 1, dp);
    // ll ans = leviTabulation(n);
    ll ans = leviSpaceOptimization(n);
    cout << ans;
    return 0;
}