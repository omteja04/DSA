/**
 * Author: omteja04
 * Created on: 07-07-2024 16:21:51
 * Description: PaintingFence
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

ll add(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}
ll mul(ll a, ll b) {
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

// !TLE
ll leviRecursion(int n, int k) {
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));

    ll ans = add(mul(leviRecursion(n - 2, k), k - 1), mul(leviRecursion(n - 1, k), k - 1));
    return ans;
}

ll leviMemoization(int n, int k, v32 &dp) {
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));
    if (dp[n] != -1)
        return dp[n];
    ll ans = add(mul(leviMemoization(n - 2, k, dp), k - 1), mul(leviMemoization(n - 1, k, dp), k - 1));
    return dp[n] = ans;
}

ll leviTabulation(int n, int k) {
    v32 dp(n + 1, -1);
    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++) {
        ll ans = add(mul(dp[i - 1], k - 1), mul(dp[i - 2], k - 1));
        dp[i] = ans;
    }
    return dp[n];
}
ll leviSpaceOptimization(int n, int k) {
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));
    ll a = k;
    ll b = add(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++) {
        ll c = add(mul(b, k - 1), mul(a, k - 1));
        a = b;
        b = c;
    }
    return b;
}
int main() {
    int n, k;
    cin >> n >> k;
    // ll ans = leviRecursion(n, k);
    // v32 dp(n + 1, -1);
    // ll ans = leviMemoization(n, k, dp);
    // ll ans = leviTabulation(n, k);
    ll ans = leviSpaceOptimization(n, k);
    cout << ans;
    return 0;
}