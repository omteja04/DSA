/**
 * Author: omteja04
 * Created on: 03-03-2024 10:38:07
 * Description: findLargestMinDistance
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
bool isPossible(vector<int> &boards, int mid, int k) {
    int painters = 1;
    int sum = 0;
    for (int &i : boards) {
        if (sum + i <= mid) {
            sum += i;
        } else {
            painters++;
            if (painters > k || i > mid) {
                // Second Condition endhuku ante manam anni boards ni pain cheyyali kabatti okavela mid kanna peddha value vunnattaiithe appudu aa board ni paint cheyyalem
                return false;
            }
            sum = i;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k) {
    //    Write your code here.
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}