/**
 * Author: omteja04
 * Created on: 03-03-2024 10:35:00
 * Description: SubSets
 **/

#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> subset;
void processSubset() {
    cout << "Subset: {";
    for (int element : subset) {
        cout << element << " ";
    }
    cout << "}\n";
}
void search(int k) {
    if (k == n) {
        processSubset();
    } else {
        search(k + 1);
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
    }
}

int main() {
    cin >> n;
    search(0);
    return 0;
}
