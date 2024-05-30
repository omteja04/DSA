/**
 * Author: omteja04
 * Created on: 30-05-2024 20:46:02
 * Description: Sort0s1s2s
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

// Better
/*
* take count of all elements and put according to each count in the array;
^ TC - O(2n)
^ SC - O(1) Modifying given array
 */
void dutchNationalFlag(int n, vector<int> &arr) {
    // Consists 3 pointers

    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k) {
        int element = arr[j];
        switch (element) {
        case 0:
            swap(arr[j], arr[i]);
            i++;
            j++;
            break;
        case 1:
            j++;
            break;
        case 2:
            swap(arr[j], arr[k]);
            k--;
        }
    }
    coutArr(n, arr);

    // ^ TC - O(n)
    // ^ SC - O(1) - Modifying given array
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    dutchNationalFlag(n, arr);
    return 0;
}