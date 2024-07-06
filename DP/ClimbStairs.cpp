/**
 * Author: omteja04
 * Created on: 30-06-2024 10:26:14
 * Description: ClimbStairs
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

int climb(int n) {
    int prev2 = 1;
    int prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int c = prev1 + prev2;
        prev2 = prev1;
        prev1 = c;
    }
    return prev1;
}

int main() {
    int n;
    cin >> n;
    cout << climb(n);
    return 0;
}