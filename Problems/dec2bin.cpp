/**
 * Author: omteja04
 * Created on: 03-03-2024 10:37:11
 * Description: dec2bin
 **/

#include <bits/stdc++.h>
using namespace std;
void dec2bin(int n) {
    int ans = 0;
    int i = 0;
    while (n) {

        // To Check the last bit
        int digit = n & 1;

        // To convert the obtained flow of digits into reverse order
        // ans = (digit << i) | ans; // Use 1 << i instead of pow(10, i)
        ans = (digit * pow(10, i)) + ans;

        // to divide by 2
        n >>= 1;
        i++;
    }
    cout << ans;
}
int main() {
    // Your code goes here
    int n;

    cin >> n;

    dec2bin(n);

    return 0;
}