/**
 * Author: omteja04
 * Created on: 29-06-2024 20:18:19
 * Description: PrintSubsequencesOfSumK
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

void search(int i, int n, vector<int> &arr, vector<int> &subset, int curr, int k) {
    // Your code goes here
    if (i >= n) {
        if (curr == k) {
            for (int ele : subset) {
                cout << ele << " ";
            }
            cout << endl;
        }
        return;
    }

    subset.push_back(arr[i]);
    curr += arr[i];
    search(i + 1, n, arr, subset, curr, k);
    curr -= arr[i];
    subset.pop_back();
    search(i + 1, n, arr, subset, curr, k);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    int k;
    cin >> k;
    vector<int> subset;
    search(0, n, arr,subset, 0, k);
    return 0;
}