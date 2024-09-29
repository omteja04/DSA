/**
 * Author: omteja04
 * Created on: 29-09-2024 18:22:11
 * Description: ImportanceOfGetline
 **/

#include <bits/stdc++.h>
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << (#x) << " = " << (x) << '\n'
using namespace std;
void levi();
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string str;
        getline(cin, str);
        cout << str << endl;
    }
    return 0;
}