/**
 * Author: omteja04
 * Created on: 31-05-2024 16:20:38
 * Description: MajorityElement
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

// Moore's Voting Algorithm
int majorityElement(vector<int> &arr) {
    int cnt = 0;
    int element;
    for (int &i : arr) {
        if (cnt == 0) {
            cnt = 1;
            element = i;
        } else if (element == i) {
            cnt++;
        } else {
            cnt--;
        }
    }
    int cnt1 = 0;
    for (int &i : arr) {
        if (i == element) {
            cnt1++;
        }
    }
    if (cnt1 > arr.size() / 2) {
        return element;
    }
    return -1;
}

/*
    ^ TC - O(n) + O(n) {If Array will definitely have majority element then There is no additional O(n)}
    ^ SC - O(1)

 */

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    cout << majorityElement(arr);
    return 0;
}