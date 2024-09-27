/**
 * Author: omteja04
 * Created on: 12-03-2024 11:55:36
 * Description: Hashing
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
vector<pair<int, int>> zeroSubArraySum(int *arr, int n) {
    unordered_map<int, vector<int>> hashTable;
    vector<pair<int, int>> ans;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum == 0) {
            ans.push_back(make_pair(0, i));
        }

        if (hashTable.find(currentSum) != hashTable.end()) {
            vector<int> ans1 = hashTable[currentSum];
            for (auto it = ans1.begin(); it != ans1.end(); it++) {
                ans.push_back(make_pair(*it + 1, i));
            }
        }

        hashTable[currentSum].push_back(i);
    }
    return ans;

}
int main() {
    int nums[] = {0, -1, 8, -5, -3, -7, 4, 2, 1};
    int N = sizeof(nums) / sizeof(nums[0]);

    vector<pair<int, int>> ans = zeroSubArraySum(nums, N);

    // if we didn’t find any subArray with 0 sum,
    // then sub-array doesn’t exists
    if (ans.size() == 0)
        cout << "No subArray exists";
    else
        for (auto k = ans.begin(); k != ans.end(); k++)
            cout << "SubArray found from Index " << k->first << " to " << k->second << endl;

    return 0;
}