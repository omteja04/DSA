/**
 * Author: omteja04
 * Created on: 29-06-2024 21:34:38
 * Description: CountOfSubSequencesOfSumK
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

int search(int i, int n, vector<int> &arr, int curr, int k) {

    if (curr > k) {
        // Only when all elements are positive

        return 0;
    }
    if (i >= n) {

        if (curr == k) {
            // for (int ele : subset) {
            //     cout << ele << " ";
            // }
            // cout << endl;
            return 1;
        }
        return 0;
    }
    // subset.push_back(arr[i]);
    curr += arr[i];
    int l = search(i + 1, n, arr, curr, k);
    curr -= arr[i];
    // subset.pop_back();
    int r = search(i + 1, n, arr, curr, k);

    return l + r;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    int k;
    cin >> k;
    cout << search(0, n, arr, 0, k);
    return 0;
}