/**
 * Author: omteja04
 * Created on: 04-06-2024 20:03:33
 * Description: LongestConsecutiveSeq
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

    * longest = 1;
    * for (ll i = 0; i < n; i++)
    *   x = arr[i]
    *   cnt = 1
    *   while(linearSearch(arr,x+1) == true)
    *       x+=1
    *       cnt++
    *   longest = max(cnt, longest)
    *
    ^ TC - O(n^2)
    ^ SC - O(1)
 */

// Better Solution
/*
 * Sort The Array
 */

int longestSeqBetter(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int longest = 1;
    int currCnt = 0;
    int leastSmaller = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (leastSmaller == arr[i] - 1) {
            currCnt++;
            leastSmaller = arr[i];
        } else if (leastSmaller != arr[i]) {
            leastSmaller = arr[i];
            currCnt = 1;
        }
        longest = max(currCnt, longest);
    }
    return longest;
}

int longestSeqOptimal(vector<int> &arr) {
    // Your code goes here
    int n = arr.size();
    if (n == 0) {
        return 0;
    }
    int longest = 1;
    unordered_set<int> s;
    for (int &i : arr) {
        s.insert(i);
    }
    for (auto &i : s) {
        if (s.find(i - 1) == s.end()) {
            int cnt = 1;
            int x = i;
            while (s.find(x + 1) != s.end()) {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

    /*
    ! Inserting into set
    *  In Best and average case unordered_set takes O(1) in worst O(n)
    ^ TC - O(n)
    ! Checking Sequence
    * the while will iterate there is next element when there is no previous element
    ^ TC ~ O(2n)

    ^ Overall TC - O(3n)

    ^ SC - O(n)
     */
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    cout << longestSeqBetter(arr) << endl;
    cout << longestSeqOptimal(arr) << endl;
    return 0;
}