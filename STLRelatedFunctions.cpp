/**
 * Author: omteja04
 * Created on: 15-05-2024 16:11:16
 * Description: STLRelatedFunctions
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
typedef long long ll;
#define cinArr(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]

void levi() {
    int num = 7;
    cout << __builtin_popcount(num) << endl;

    string s = "123";
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));


    
}

int main() {
    levi();
    return 0;
}