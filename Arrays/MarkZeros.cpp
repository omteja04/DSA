/**
 * Author: omteja04
 * Created on: 06-06-2024 18:08:46
 * Description: MarkZeros
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

void markZerosBrute(vector<vector<int>> &arr) {

    auto markRow = [&](int i) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i][j] != 0) {
                arr[i][j] = -1;
            }
        }
    };

    auto markCol = [&](int j) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i][j] != 0) {
                arr[i][j] = -1;
            }
        }
    };

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i][j] == 0) {
                markRow(i);
                markCol(j);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }

    // ^ TC O(n^3)
}

void markZerosBetter(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    int row[n] = {0};
    int col[m] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                arr[i][j] = 0;
            }
        }
    }
    // ^ TC - O(2*m*n)
    // ^ SC - O(m + n)
}

void markZerosOptimal(vector<vector<int>> &arr) {
    // First Row is Used for Column
    // First Col is Used for row
    // Since arr[0][0] will be common we use col0 variable to indicate 1st column
    // int row[n] = {0}; -> arr[i][0]
    // int col[m] = {0}; -> arr[0][j]
    int col0 = 1;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j] == 0) {
                // Mark ith row
                arr[i][0] = 0;
                // mark jth column
                if (j != 0) {
                    arr[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < arr.size(); i++) {
        for (int j = 1; j < arr[0].size(); j++) {
            if (arr[i][j] != 0) {
                // check for col and row
                if (arr[0][j] == 0 || arr[i][0] == 0) {
                    arr[i][j] = 0;
                }
            }
        }
    }
    if (arr[0][0] == 0) {
        for (int j = 1; j < arr[0].size(); j++) {
            arr[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i][0] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    markZerosOptimal(arr);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}