/**
 * Author: omteja04
 * Created on: 21-05-2024 10:49:50
 * Description: Recursion-2
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

void revArray(int i, int *arr, int n) {
    // Your code goes here
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    revArray(i + 1, arr, n);
}

bool checkPalindrome(string &s, int n, int i) {
    if (i >= n / 2)
        return true;
    if (s[i] != s[n - i - 1])
        return false;
    return checkPalindrome(s, n, i + 1);
}
int main() {
    // int n;
    // cin >> n;
    // int arr[n];
    // cinArr(n, arr);
    // revArray(0, arr, n);
    // coutArr(n, arr);

    string s;
    cin >> s;
    int n = s.length();
    if (checkPalindrome(s, n, 0)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}