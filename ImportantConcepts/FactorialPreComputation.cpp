/**
 * Author: omteja04
 * Created on: 29-09-2024 22:53:42
 * Description: FactorialPreComputation
 **/
#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
long long fact[N + 1];
int main() {
    fact[0] = fact[1] = 1;

    for (int i = 2; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int num;
        cin >> num;
        cout << fact[num] << endl;
    }

    return 0;
}











