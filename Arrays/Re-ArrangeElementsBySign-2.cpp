/**
 * Author: omteja04
 * Created on: 01-06-2024 12:46:21
 * Description: Re-ArrangeElementsBySign-2
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

//* Unequal no of elements

// * Take two arrays positive and negative and insert each element in another iteration

//! which array has min size upto that all in order remaining will be added in same order

// ^ TC - O(n) + O(min(pos.size, neg.size)) + O(left overs) --> O(2n)
// ^ SC - O(n)
vector<int> reArrange(vector<int> &arr) {
    vector<int> res(arr.size());
    vector<int> posArray;
    vector<int> negArray;
    for (int &i : arr) {
        if (i < 0)
            negArray.push_back(i);
        else if (i > 0)
            posArray.push_back(i);
    }
    if (posArray.size() > negArray.size()) {
        for (int i = 0; i < negArray.size(); i++) {
            res[2 * i] = posArray[i];
            res[2 * i + 1] = negArray[i];
        }
        // Left Overs
        int ind = negArray.size() * 2;
        for (int i = negArray.size(); i < posArray.size(); i++) {
            res[ind++] = posArray[i];
        }
    }
    if (posArray.size() < negArray.size()) {
        for (int i = 0; i < posArray.size(); i++) {
            res[2 * i] = posArray[i];
            res[2 * i + 1] = negArray[i];
        }
        // Left Overs
        int ind = posArray.size() * 2;
        for (int i = posArray.size(); i < negArray.size(); i++) {
            res[ind++] = negArray[i];
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    vector<int> res = reArrange(arr);
    coutArr(n, res);
    return 0;
}