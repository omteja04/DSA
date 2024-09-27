/**
 * Author: omteja04
 * Created on: 13-03-2024 15:19:04
 * Description: ArrayPermutation
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
void search(vector<int> &nums, unordered_set<int> &chosen) {
    if (permutation.size() == nums.size()) {
        processPermutation();
    } else {
        for (size_t i = 0; i < nums.size(); i++) {
            if (chosen.find(nums[i]) != chosen.end()) {
                continue;
            }
            chosen.insert(nums[i]);
            permutation.push_back(nums[i]);
            search(nums, chosen);
            chosen.erase(nums[i]);
            permutation.pop_back();
        }
    }
}

int main() {
    vector<int> nums = {1, 3, 5};
    unordered_set<int> chosen;

    search(nums, chosen);
    return 0;
}