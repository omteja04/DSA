/**
 * Author: omteja04
 * Created on: 03-03-2024 10:33:59
 * Description: FloorSqrt
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
int floorSqrt(int n) {
    // Write your code here.
    int low = 0;
    int high = n;
    int ans = -1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        int square = mid * mid;
        if (square == n) {
            return mid;
        } else if (square > n) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    // Your code goes here
    int n;
    cin >> n;
    cout << floorSqrt(n);
    return 0;
}