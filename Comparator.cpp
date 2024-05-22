/**
 * Author: omteja04
 * Created on: 15-05-2024 15:57:58
 * Description: Comparator
 **/
#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
typedef long long ll;
#define cinArr(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]

/**
 * The function `comp` compares pairs of integers based on their second elements, breaking ties by
 * comparing the first elements in descending order.
 *
 * The function `comp` takes two pairs of integers as input parameters: `p1` and `p2`. Each
 * pair consists of two integers, where the first integer is accessed using `p1.first` and `p2.first`,
 * and the second integer is accessed using `p1.second`
 * The `comp` function you provided is a comparison function for pairs of integers. It
 * compares the pairs based on the second element first, and if the second elements are equal, it
 * compares based on the first element.
 *
 * @return The function `comp` compares two pairs of integers based on their second elements first, and
 * if they are equal, it compares based on the first elements. The function returns `true` if the first
 * pair should come before the second pair in the ordering, and `false` otherwise.
 */
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    if (p1.first > p2.first)
        return true;
    return false;
}

void levi() {
    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    sort(a, a + 3, comp);
    for (auto it : a) {
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    levi();
    return 0;
}