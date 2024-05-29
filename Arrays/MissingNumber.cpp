/**
 * Author: omteja04
 * Created on: 29-05-2024 11:00:56
 * Description: MissingNumber
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

// NOTE -  Brute force
/*
   * for i 1 to N
   *     flag = 0
   *     for j 0 to n-1
   *         if arr[j] == i
   *             flag = 1 number exists
   *             break
   *     if flag == 0 number not exists
   *         return i

    ^ TC - O(n^2)
    ^ SC - O(1)
 */

// NOTE - Better Solution
/*
    ! Declare a hash vector of size n + 1 initially with zeros
    ! iterate given array and mark 1 in hash vector
    ! not iterate to find which in not marked 1 so it is the answer
 */

// Algorithm
/*
    * hash[n+1] = {0}
    * for i o to n-1
    *     hash[arr[i]] = 1
    * for 1 to n
    *     if hash[i] == 0
    *         return i

    ^ TC - O(n)
    ^ SC - O(n)

 */

// Optimal Implementation
// Using Sum
// Using XOR
int missingNumber(int N, vector<int> &arr) {
    // Your code goes here
    int actualSum = N * (N + 1) / 2;
    int arrSum = 0;
    int n = N - 1;

    for (int i = 0; i < n; i++) {
        arrSum += i;
    }
    return actualSum - arrSum;

    //^ TC - O(n)
    //^ SC - O(1)
}

/*
XOR of the two same numbers is Zero -> a ^ a = 0
XOR of a number with zero is the number itself -> a ^ 0  = a
 */

int missingNumberUsingXor(int N, vector<int> &arr) {
    int xor1 = 0;
    int xor2 = 0;
    int n = N - 1;
    for (int i = 0; i < n; i++) {
        xor1 ^= (i + 1);
        xor2 ^= arr[i];
    }
    xor1 ^= N;
    return xor1 ^ xor2;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N - 1);
    cinArr(N - 1, arr);
    cout << missingNumber(N, arr) << endl;
    cout << missingNumberUsingXor(N, arr) << endl;
    return 0;
}