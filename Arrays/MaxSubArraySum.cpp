/**
 * Author: omteja04
 * Created on: 31-05-2024 18:58:32
 * Description: MaxSubArraySum
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

int maxSubArraySum(vector<int> &arr) {
    // Your code goes here
    ll sum = 0;
    ll maxi = LONG_MIN;

    int currStart;
    int ansStart = -1;
    int ansEnd = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (sum == 0) {
            currStart = i;
        }
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = currStart;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    // To Print The Sub Array
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // If no maxSum is > 0 then return 0
    if (maxi < 0) {
        return 0;
    }
    return maxi;
    // ^ TC - O(n)
    // ^ SC - O(1)
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    cout << maxSubArraySum(arr);
    return 0;
}