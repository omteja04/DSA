/**
 * Author: omteja04
 * Created on: 29-05-2024 12:42:06
 * Description: LongestSubArrayWithSumK
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
   * len = 0
   * for i 0 to n-1
   *     for j i to n-1
   *         s = 0
   *         for k i  to j
   *             s+=arr[k]
   *             if s == k
   *                 len = max(lej - i + 1)
   * return len

    ^ TC ~ O(n^3)
    ^ SC - O(1)

 */
// Brute force - 2
/*
   * len = 0
   * for i 0 to n-1
   *     s = 0
   *     for j i to n-1
    *       s+=arr[j]
    *       if s == k
    *           len = max(lej - i + 1)
   * return len

    ^ TC ~ O(n^2)
    ^ SC - O(1)

 */

//  Better Solution - Prefix Sum (If only positives and zero)
// This is optimal if the array contains both positive and negative elements.

int longestSubArrayWithSumKBetter(int k, vector<int> &arr) {
    int n = arr.size();
    map<long long, int> prefixSum;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        long long remainder = sum - k;
        if (prefixSum.find(remainder) != prefixSum.end()) {
            int len = i - prefixSum[remainder];
            maxLen = max(maxLen, len);
        }
        // by Writing the line `prefixSum[sum] = i;` inside an if we assure that it works even when there are zeros in the sub array
        if (prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }
    return maxLen;

    // ^ TC - O(n * log n) -> ordered map
    // ^ TC - O(n * 1) -> unordered map -- if worst case (collisions) O(n * n)
    // ^ SC - O(n)
}

// Optimal Implementation work if there are only positives
int longestSubArrayWithSumKOptimal(int k, vector<int> &arr) {

    int left = 0, right = 0;
    long long sum = arr[0];
    int n = arr.size();
    int maxLen = 0;
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n) {
            sum += arr[right];
        }
    }
    return maxLen;


    // ^ TC - O(2n) {2nd loop won't run always}
    // ^ SC - O(1)
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    cinArr(n, array);
    int k;
    cin >> k;
    int res1 = longestSubArrayWithSumKBetter(k, array);
    int res2 = longestSubArrayWithSumKOptimal(k, array);
    cout << res1 << " " << res2 << endl;
    return 0;
}