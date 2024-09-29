/**
 * Author: omteja04
 * Created on: 21-04-2024 13:04:02
 * Description: BinaryExponentiation
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
typedef long long ll;
#define cinArr(n, arr)          \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

ll binPowerRec(int x, int y) {
    if (y == 0)
        return 1;
    int res = binPowerRec(x, y / 2);
    if (y & 1) {
        return res * res * x;
    } else
        return res * res;
}
ll binPower(int x, int y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res *= x;
        res *= res;
        y >>= 1;
    }
    return res;
}
void levi() {
    // Your code goes here
    int n;
    cin >> n;
    int power;
    cin >> power;
    cout << binPowerRec(n, power) << endl;
    cout << binPower(n, power) << endl;
}

int main() {

    levi();

    return 0;
}