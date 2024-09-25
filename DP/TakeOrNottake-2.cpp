/**
 * Author: omteja04
 * Created on: 05-09-2024 21:34:47
 * Description: demo
 **/

#include <bits/stdc++.h>
using namespace std;
#define boo cout << "Boo" << '\n'
#define cin1d(n, arr)          \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
#define cout1f(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cout << arr[i] << ' '
using ll = long long;
using vi = vector<int>;
const int MOD = 1000000007;

int leviMemo(int ind, vector<int> &arr, vector<int> &dp) {
    if (ind < 0) {
        return 0;
    }
    if (dp[ind] != -1) {
        return dp[ind];
    }
    int notTake = 0 + leviMemo(ind - 1, arr, dp);
    if (arr[ind] <= 0) {
        dp[ind] = leviMemo(ind - 1, arr, dp);
    } else {
        dp[ind] = arr[ind] + leviMemo(ind - 2, arr, dp);
    }
    return dp[ind] = max(dp[ind], notTake);
}
void levi() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> dp1(n + 1, -1);
    int withLast = leviMemo(n - 1, arr, dp1);
    vector<int> dp2(n + 1, -1);
    int withoutLast = leviMemo(n - 2, arr, dp2);
    cout << max(withLast, withoutLast);
}

int main() {
    levi();
    return 0;
}