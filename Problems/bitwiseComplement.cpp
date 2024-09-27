/**
 * Author: omteja04
 * Created on: 03-03-2024 10:37:25
 * Description: bitwiseComplement
 **/

#include <iostream>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n;
        int mask = 0;
        while (m) {
            mask = (mask << 1) | 1;
            m >>= 1;
        }

        int num = (~n) & mask;

        return num;
    }
};
// https://leetcode.com/problems/complement-of-base-10-integer/description/
int main() {
    Solution solution;

    // Example usage
    int num;
    cin >> num;
    int complement = solution.bitwiseComplement(num);

    cout << "Bitwise complement of " << num << " is: " << complement << endl;

    return 0;
}
