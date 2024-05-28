/**
 * Author: omteja04
 * Created on: 28-05-2024 22:10:07
 * Description: MoveAllZerosToEnd
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

/*
 * Brute force :- Take a temp array of given array size and iterate the given array and store all non-zero elements in the temporary and  replace the temp array values with given array. Now fill remaining places with zeros.

^ TC - O(x) + O(n - x) + O(n) -> O(2n)
^ SC - O(x) -- worst case O(n)

 */

// Optimal implementation
void moveZeros(int n, vector<int> &arr) {
    // Your code goes here
    int i = 0, j = 0;
    while (i < n) {
        if (arr[i] != 0) {
            if (i != j) {
                swap(arr[i], arr[j]);
            }
            j++;
        }
        i++;
    }
    // return arr;

    // TC -  O(n)
    // SC O(1) -- modifying given array
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    moveZeros(n, arr);
    coutArr(n, arr);
    return 0;
}