/**
 * Author: omteja04
 * Created on: 28-06-2024 20:09:38
 * Description: PrintSubsequences
 **/

/*
Time Complexity :- O(2^n * n)
Space Complexity :- O(n)
 */
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

vector<int> subset;

void process() {
    if (subset.size() == 0) {
        cout << "{}\n";
        return;
    }
    for (auto ele : subset) {
        cout << ele << " ";
    }
    cout << '\n';
}

void search(int i, int n, vector<int> &arr) {
    if (i >= n) {
        process();
        return;
    }
    search(i + 1, n, arr);
    subset.push_back(arr[i]);
    search(i + 1, n, arr);
    subset.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    search(0, n, arr);
    return 0;
}