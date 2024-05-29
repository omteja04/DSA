/**
 * Author: omteja04
 * Created on: 29-05-2024 19:13:47
 * Description: TwoSum
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

// better implementation

/*
 * Take a hashmap with element and index as key-value pairs
 * iterate and store the element and index
 * check if (target  - element) present in the map if present return both indices
 * else insert the element and its index
 */

string twoSumBetter(vector<int> &arr, int target) {
    // Your code goes here
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        int a = arr[i];
        int remaining = target - a;
        if (mp.find(remaining) != mp.end()) {
            return "YES";
        }
        mp[a] = i;
    }
    return "NO";
}

// ^ TC - O(n * log n) ordered map
// ^ TC - O(n * 1) unordered map - WorstCase - O(n*n)
// ^ SC - O(n)

string twoSumOptimal(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if(sum ==target)
            return "YES";
        else if(sum < target)
            left++;
        else right--;
    }
    return "NO";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    int target;
    cin >> target;
    cout << twoSumBetter(arr, target);
    cout << twoSumOptimal(arr, target);
    return 0;
}