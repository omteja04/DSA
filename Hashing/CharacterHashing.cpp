/**
 * Author: omteja04
 * Created on: 21-05-2024 13:26:22
 * Description: CharacterHashing
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

void levi() {
    string s;
    cin >> s;

    // precompute

    int hash[256] = {0};
    for (int i = 0; i < s.length(); i++) {
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while (q--) {
        char ch;
        cin >> ch;
        cout << hash[ch] << " ";
    }
}

int main() {
    levi();
    return 0;
}