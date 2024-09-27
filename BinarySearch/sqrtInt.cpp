/**
 * Author: omteja04
 * Created on: 03-03-2024 10:37:43
 * Description: sqrtInt
**/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
int sqrtInt(int n)
{
    int low = 0;
    int high = n;
    int ans = -1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        if (square > n)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}
double precision(int n,int precisionCnt,int tempSol){
    double factor = 1;
    double ans = tempSol;
    for (int i = 0;i<precisionCnt;i++){
        factor = factor / 10;
        for (double  j = ans; j*j < n; j+=factor){
            ans = j;

        }
    }
    return ans;
}
int main() {
    // Your code goes here
    int n;
    cin >> n;
    int tempSol=sqrtInt(n);
    int precisionCnt;
    cin >> precisionCnt;
    cout << "Answer : " << precision(n, precisionCnt, tempSol);

    return 0;
}