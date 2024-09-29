/**
 * Author: omteja04
 * Created on: 22-04-2024 08:16:57
 * Description: EuclideanAlgo
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
typedef long long ll;
#define cinArr(n, arr)          \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a,int b){
    return (a * b )/ gcd(a, b);
}
void levi() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
}

int main() {

    levi();

    return 0;
}