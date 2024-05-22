/**
 * Author: omteja04
 * Created on: 21-05-2024 12:21:09
 * Description: Hashing
 **/

// Hashing :- Pre-store / Fetching

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

// Inside main we can declare a integer array only upto 10^6
// Inside main we can declare a boolean array only upto 10^7

// But Globally we can declare a integer array upto 10^7 (1e7)
// But Globally we can declare a boolean array upto 10^8 (1e8)

void levi() {

    int n;
    cin >> n;
    int arr[n];
    cinArr(n, arr);

    // precompute
    int hash[100001] = {0}; // 10^5

    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    // queries

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << hash[x] << '\n';
    }
}

int main() {
    levi();
    return 0;
}