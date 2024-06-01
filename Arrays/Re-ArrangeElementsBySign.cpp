/**
 * Author: omteja04
 * Created on: 01-06-2024 12:18:37
 * Description: Re-ArrangeElementsBySign
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

// BruteForce

// * Take two arrays positive and negative and insert each element in another iteration

/*
    8
    1 2 3 -5 -4 1 -9 -10

    1 -5 2 -4 3 -9 1 -10
    *   pos[]
    *   neg[]
    *   for i 0 to n-1
    *       if(arr[i] > 0) add to pos
    *       if(arr[i] < 0) add to neg
    *   for i 0 to n/2
    *       arr[2*i] = pos[i]
    *       arr[2*i + 1] = pos[i]


    ^ TC - O(n) + O(n / 2)
    ^ SC - O(n)
 */

vector<int> reArrange(vector<int> &arr) {
    vector<int> res(arr.size());
    int posInd = 0;
    int negInd = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            res[negInd] = arr[i];
            negInd += 2;
        } else {
            res[posInd] = arr[i];
            posInd += 2;
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