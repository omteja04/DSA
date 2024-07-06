/**
 * Author: omteja04
 * Created on: 01-07-2024 22:36:48
 * Description: HouseRobber-2
 **/

// https://leetcode.com/problems/house-robber-ii/

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
typedef vector<int> v32;
int fun(vector<int> &arr) {
    int n = arr.size();
    int past = 0;
    int just = arr[0];
    for (int i = 1; i < n; i++) {
        int take = arr[i];
        if (i > 1)
            take += past;
        int notTake = just;

        int curr = max(take, notTake);
        past = just;
        just = curr;
    }
    return just;
}
int levi(v32 &nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    if (n == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            temp1.push_back(nums[i]);
        }
        if (i != (n - 1)) {
            temp2.push_back(nums[i]);
        }
    }
    return max(fun(temp1), fun(temp2));
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    cout << levi(arr);
    return 0;
}