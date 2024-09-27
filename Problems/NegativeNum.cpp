/**
 * Author: omteja04
 * Created on: 03-03-2024 10:36:47
 * Description: NegativeNum
 **/

#include <bits/stdc++.h>
using namespace std;
void negativeNum(int n) {
    // cout << "Hi" << endl;
    int arr[32] = {0};
    // int j = 0;
    n = abs(n);
    int i = 31;
    int carry = 1;
    // cout << arr[i];

    while (n != 0) {

        int digit = n & 1;
        arr[i--] = digit;
        n >>= 1;
    }
    // while(i>=0){
    //     arr[i--] = 0;
    // }

    i = 31;
    while (i >= 0) {
        arr[i] = !arr[i];
        i--;
    }

    for (int i = 31; i >= 0 and carry; i--) {
        int sum = arr[i] + carry;
        arr[i] = sum & 1;
        carry = sum >> 1;
    }
    for (int i = 0; i < 32; i++) {
        cout << arr[i];
    }
}

int main() {
    // Your code goes here
    int n;
    cin >> n;
    negativeNum(n);
    return 0;
}