/**
 * Author: omteja04
 * Created on: 29-06-2024 22:00:28
 * Description: Fibonacci
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

//^ Memoization
int Fibonacci(int n, vector<int> &dp) {
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = Fibonacci(n - 1, dp) + Fibonacci(n - 2, dp);

    // TC - O(n)
    // SC - O(n + n) - Recursion Stack Space + Array
}

//^ Tabulation
int fib(int n, vector<int> &dp) {
    if (n <= 1)
        return n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];

    // TC - O(n)
    // SC - O(n)
}

// ^ Space Optimization
void fib2(int n) {
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    cout << prev1;
}

int main() {
    int n;
    cin >> n;
    // int dp[n + 1];
    // memset(dp, -1, sizeof(dp));
    vector<int> dp(n + 1, -1);
    cout << Fibonacci(n, dp) << " " << fib(n, dp)<<" ";
    fib2(n);

    return 0;
}