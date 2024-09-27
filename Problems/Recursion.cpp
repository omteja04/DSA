/**
 * Author: omteja04
 * Created on: 21-05-2024 10:19:13
 * Description: Recursion
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
typedef long long ll;
#define cinArr(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]

void numSum(int i, int sum) {
    // Your code goes here
    if (i < 1) {
        cout << sum << "\n";
        return;
    }
    numSum(i - 1, sum + i);
}
int fact(int n) {
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}
int main() {
    numSum(10, 0);
    cout << fact(5) << endl;
    return 0;
}