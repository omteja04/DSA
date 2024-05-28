/**
 * Author: omteja04
 * Created on: 28-05-2024 22:43:47
 * Description: UnionOfTwoSortedArrays
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

// Brute force

/*
 * Iterate 2 arrays and insert all the elements in 'set'

^ TC - O(n1 log n) + O(n2 log n) + O(n1 + n2)
^ SC - O(n1 + n2) + O(n1 + n2) -> to return the array

 */

// Optimal implementation :- Since both are sorted
vector<int> UnionOf2SortedArrays(vector<int> &v1, vector<int> &v2) {
    // Your code goes here

    vector<int> unionArr;
    int i = 0, j = 0;
    int n1 = v1.size();
    int n2 = v2.size();
    while (i < n1 && j < n2) {
        if (v1[i] <= v2[j]) {
            if (unionArr.empty()||unionArr.back() != v1[i]) {
                unionArr.push_back(v1[i]);
            }
            i++;
        } else if (v1[i] > v2[j]) {
            if (unionArr.empty() || unionArr.back() != v2[j]) {
                unionArr.push_back(v2[j]);
            }
            j++;
        } 
    }
    while (i < n1) {
        if (unionArr.empty() || unionArr.back() != v1[i]) {
            unionArr.push_back(v1[i]);
        }
        i++;
    }
    while (j < n2) {
        if (unionArr.empty() || unionArr.back() != v2[j]) {
            unionArr.push_back(v2[j]);
        }
        j++;
    }

    return unionArr;


    // TC - O(n1 + n2)
    // SC - O(n2 + n2) -> For Result
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    cinArr(n, arr1);
    cinArr(m, arr2);
    vector<int> unionResult = UnionOf2SortedArrays(arr1, arr2);
    coutArr(unionResult.size(), unionResult);
    cout << '\n';
    return 0;
}