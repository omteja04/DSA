/**
 * Author: omteja04
 * Created on: 13-03-2024 15:07:25
 * Description: Permutations
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
vector<int> permutation;
void processPermutation() {
    cout << "Permutation: {";
    for (int element : permutation) {
        cout << element << " ";
    }
    cout << "}\n";
}
void search(int n, vector<bool> &chosen) {
    if (permutation.size() == n) {
        processPermutation();
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) {
                continue;
            }
            chosen[i] = true;
            permutation.push_back(i);
            search(n, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<bool> chosen(n, false);
    search(n, chosen);
    return 0;
}