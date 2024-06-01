/**
 * Author: omteja04
 * Created on: 01-06-2024 20:28:22
 * Description: LeadersInAnArray
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

// Brute Force

// For every element iterate all the right elements and check if any element is greater or not

/*
    * for i (0 to n-1)
    *   leader = true
    *   for j (i to n-1)
    *       if arr[j]  > arr[i]
    *           leader = false
    *           break
    *   if leader == true store in ans vector
    *
    *
    ^ TC - O(n^2)
    ^ SC - O(n) {To store}

 */

vector<int> leaders(vector<int> &arr) {
    // Your code goes here
    vector<int> leaders;
    int maxi = INT_MIN;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] > maxi) {
            leaders.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    sort(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    vector<int> res = leaders(arr);
    coutArr(res.size(), res);
    return 0;
}