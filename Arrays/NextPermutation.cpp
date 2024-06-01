/**
 * Author: omteja04
 * Created on: 01-06-2024 13:12:08
 * Description: NextPermutation
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

// NOTE
// Generate all permutations
// do linear search
// find answer

// ^ TC  - O(n! * n) {Generate and iterate over it}

//  Better

// NOTE
//~ STL next_permutation(arr.begin(), arr.end); {return nothing changes inplace}

/* ---------------------------------- */

// ! Observation

/*
   * next element has longer prefix match with current element (Figure out BreakPoint - a[i] < a[i+1])

    *the first changing number should be greater than the current element which is smallest possible.

    *after doing 2nd step remaining elements should be in ascending order

 */

// ^ The Breakpoint will be between n - 2 and 0
// If No breakpoint reverse the array

// ! Algorithm

/*
    breakpoint = -1
    for i (n - 2) to 0
        if arr[i] < arr[i+1]
            breakpoint = i
            break;
    if breakpoint == -1
        return reverse of array

    for i (n - 1) to breakpoint - 1
        if arr[i] > arr[breakpoint]
            swap(arr[i], arr[breakpoint])
            break
    * {since the array will be in increasing from last to breakpoint  we can directly reverse it}

    reverse from arr + breakpoint to arr.end()

 */

vector<int> permutation(vector<int> &arr) {
    int breakpoint = -1;
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            breakpoint = i;
            break;
        }
    }
    if (breakpoint == -1) {
        reverse(arr.begin(), arr.end());
    }
    for (int i = n - 1; i > breakpoint; i--) {
        if (arr[i] > arr[breakpoint]) {
            swap(arr[i], arr[breakpoint]);
            break;
        }
    }
    reverse(arr.begin() + breakpoint + 1, arr.end());
    return arr;

    // ^ TC - O(3n)
    // ^ SC - O(1) {Modifying Array}
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);

    vector<int> res = permutation(arr);
    coutArr(n, res);
    return 0;
}