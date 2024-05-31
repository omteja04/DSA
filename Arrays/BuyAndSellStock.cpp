/**
 * Author: omteja04
 * Created on: 31-05-2024 21:36:54
 * Description: BuyAndSellStock
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

int maxProfit(vector<int> &arr) {
    //* If you want to sell a stock on i th day then buy it when the stock is minimum from 1st to i-1th day
    int minimumCostPrice = arr[0];
    int profit = 0;
    for (int i = 1; i < arr.size(); i++) {
        int sellingPrice = arr[i];
        profit = max(profit, sellingPrice - minimumCostPrice);
        minimumCostPrice = min(minimumCostPrice, arr[i]);
    }
    return profit;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cinArr(n, arr);
    cout << maxProfit(arr);
    return 0;
}