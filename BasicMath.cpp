/**
 * Author: omteja04
 * Created on: 15-05-2024 16:16:00
 * Description: BasicMath
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
typedef long long ll;
#define cinArr(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
int countDigits(int n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
    // return log10(n) + 1;
}

int reverse(int n) {
    int rev = 0;
    while (n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool palindrome(int n) {
    return n == reverse(n);
}
bool checkArmstrong(int n) {
    int digits = log10(n) + 1;
    int temp = n;
    int num = 0;
    while (temp) {
        num += pow(temp % 10, digits);
        temp /= 10;
    }
    return num == n;
}
void printFactors(int n) {
    vector<int> v;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n / i) {
                v.push_back(n / i);
            }
        }
    }
    for (int &it : v)
        cout << it << " ";
    cout << endl;
}

bool isPrime(int n) {
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void levi() {
    int n;
    cin >> n;

    // cout << countDigits(n) << endl;
    // cout << reverse(n) << endl;
    // cout << palindrome(n) << endl;
    // cout<<checkArmstrong(n) << endl;
    // printFactors(n);
    // cout << isPrime(n) << endl;
    cout << gcd(10, 2) << endl;
}

int main() {
    levi();
    return 0;
}