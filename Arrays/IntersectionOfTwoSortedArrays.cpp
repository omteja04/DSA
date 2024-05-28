/**
 * Author: omteja04
 * Created on: 28-05-2024 23:23:46
 * Description: IntersectionOfTwoSortedArrays
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

// NOTE -
/*
 *    visited[n2] = {0}
 *    for i 0 to n1-1
 *        for j 0 to n2-1
 *            if a[i] == b[j] and visited[i] == 0
 *                add a[i] to answer
 *                visited[i] = 1
 *                break
 *            if b[j] > a[i]
 *                break;

    ^ TC - O(n1 * n2)
    ^ SC - O(n2)
 */

vector<int> IntersectionOf2SortedArrays(vector<int> &v1, int n, vector<int> &v2, int m) {
    // Your code goes here
    vector<int> res;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (v1[i] == v2[j]) {
            res.push_back(v1[i]);
            i++;
            j++;
        } else if (v1[i] > v2[j]) {
            j++;
        } else if (v1[i] < v2[j]) {
            i++;
        }
    }
    return res;


// TC - O(n1 + n2)

// SC - O(n1 + n2) TO return array

}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    cinArr(n, arr1);
    cinArr(m, arr2);
    vector<int> intersectionResult = IntersectionOf2SortedArrays(arr1, n, arr2, m);
    coutArr(intersectionResult.size(), intersectionResult);
    cout << '\n';
    return 0;
}