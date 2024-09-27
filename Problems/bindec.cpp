/**
 * Author: omteja04
 * Created on: 03-03-2024 10:37:32
 * Description: bindec
 **/

#include <bits/stdc++.h>
using namespace std;

void bindec(int n) {
    int ans = 0;
    int i = 0;
    while (n != 0) {
        int digit = n % 10;
        if (digit) {
            ans = ans + pow(2, i);
        }
        i++;
        n /= 10;
    }
    cout << ans;
}

int main() {
    // Your code goes here
    int n;
    cin >> n;
    bindec(n);
    return 0;
}