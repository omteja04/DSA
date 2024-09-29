/**
 * Author: omteja04
 * Created on: 02-03-2024 21:13:11
 * Description: MinOperations
 **/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int min_operations(vector<int> &nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());

    int operations = 0;
    while (minHeap.size() >= 2 && minHeap.top() < k) {
        long long x = minHeap.top();
        minHeap.pop();
        long long y = minHeap.top();
        minHeap.pop();

        long long new_element = min(x, y) * 2 + max(x, y);
        minHeap.push(new_element);

        operations++;
    }

    return (minHeap.top() >= k) ? operations : -1;
}

int main() {
    vector<int> nums = {1000000000, 999999999, 1000000000, 999999999, 1000000000, 999999999};
    int k = 1000000000;

    int result = min_operations(nums, k);

    cout << result << endl;

    return 0;
}
