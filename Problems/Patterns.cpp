/**
 * Author: omteja04
 * Created on: 03-03-2024 10:35:13
 * Description: Patterns
 **/


#include <bits/stdc++.h>
using namespace std;
void pattern1(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << '*' << " ";
            j += 1;
        }
        cout << '\n';
        i += 1;
    }
}
void pattern2(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << i << " ";
            j += 1;
        }
        cout << '\n';
        i += 1;
    }
}
void pattern3(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << j << " ";
            j += 1;
        }
        cout << '\n';
        i += 1;
    }
}
void pattern4(int n) {
    int i = 1;
    int k = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << k++ << " ";
            // k += 1;
            j += 1;
        }
        cout << '\n';
        i += 1;
    }
}
void pattern5(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= i) {
            cout << '*' << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }
}
void pattern6(int n) {
    int i = 1;
    int k = 1;
    while (i <= n) {
        int j = 1;
        while (j <= i) {
            cout << k << ' ';
            k += 1;
            j += 1;
        }
        cout << endl;
        i += 1;
    }
}
void pattern7(int n) {
    int i = 1;
    while (i <= n) {
        // int j = i;
        // int k = i;
        // while(j<2*i){ // while(j<=i)
        //     cout << j << " ";
        //     j++;
        //     // k++;
        // }
        int j = 0;
        while (j < i) {
            cout << i + j << ' ';
            j = j + 1;
        }
        cout << endl;
        i++;
    }
}
void pattern8(int n) {
    int i = 1;
    while (i <= n) {
        // int j = i;
        // while(j>0){
        //     cout << j << " ";
        //     j--;
        // }
        int j = 1;
        while (j <= i) {
            cout << i - j + 1 << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern9(int n) {
    int i = 1;
    // char s = 'A';
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << (char)('A' + i - 1) << " ";
            j++;
        }
        // s++;
        cout << endl;
        i++;
    }
}
void pattern10(int n) {
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << (char)('A' + j - 1) << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern11(int n) {
    int i = 1;
    char s = 'A';
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << s << " ";
            j++;
            s++;
        }
        cout << endl;
        i++;
    }
}
void pattern12(int n) {
    int i = 1;

    while (i <= n) {
        // char s = 'A' + i - 1;
        int j = 1;
        while (j <= n) {
            cout << (char)('A' + i + j - 2) << " ";
            j++;
            // s++;
        }
        cout << endl;
        i++;
    }
}
void pattern13(int n) {
    int i = 1;
    while (i <= n) {
        // char s = 'A'+i-1;
        int j = 1;
        while (j <= i) {
            cout << (char)('A' + i + j - 2) << " ";
            // s++;
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern14(int n) {

    int i = 1;
    while (i <= n) {

        int j = 1;
        char s = 'A' + n - i;
        while (j <= i) {
            // char s = 'A' + n - j;
            /*  D
                D C
                D C B
                D C B A
            */

            cout << s << " ";
            s++;
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern15(int n) {
    int i = 1;
    while (i <= n) {
        int j = n - i;
        while (j) {
            cout << " ";
            j--;
        }
        int k = 1;
        while (k <= i) {
            cout << "*";
            k++;
        }
        cout << endl;
        i++;
    }
}
void pattern16(int n) {
    int i = 1;
    while (i <= n) {

        int space = n - i + 1;
        while (space < n) {
            cout << " ";
            space++;
        }

        int j = n - i + 1;
        while (j) {
            cout << "*";
            j--;
        }
        cout << endl;
        i++;
    }
}
void pattern17(int n) {
    int i = 1;
    while (i <= n) {
        int space = n - i + 1;
        while (space < n) {
            cout << "  ";
            space++;
        }

        int j = n - i + 1;
        while (j) {
            cout << i << " ";
            j--;
        }
        cout << endl;
        i++;
    }
}
void pattern18(int n) {
    int i = 1;
    while (i <= n) {
        int space = n - i;
        while (space) {
            cout << "  ";
            space--;
        }

        int j = 1;
        while (j <= i) {
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern19(int n) {
    int i = 1;
    while (i <= n) {
        int space = n - i + 1;
        while (space < n) {
            cout << "  ";
            space++;
        }
        int j = i;
        while (j <= n) {
            cout << j << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern20(int n) {
    int i = 1;
    int num = 1;
    while (i <= n) {
        int space = n - i;
        while (space) {

            cout << "  ";
            space--;
        }
        int j = 1;
        while (j <= i) {
            cout << num << " ";
            num++;
            j++;
        }
        i++;
        cout << endl;
    }
}
void pattern21(int n) {
    int i = 1;
    while (i <= n) {
        int space = n - i;
        while (space) {
            cout << "  ";
            space--;
        }
        int j = 1;
        while (j <= i) {
            cout << j << " ";
            j++;
        }

        int k = i - 1;

        while (k > 0) {
            cout << k << " ";
            k--;
        }
        cout << endl;
        i++;
    }
}
void pattern22(int n) {
    int i = 1;
    while (i <= n) {

        int j = 1;
        while (j <= n - i + 1) {
            cout << j << " ";
            j++;
        }
        int star = i - 1;
        while (star > 0) {
            cout << "* * ";
            star--;
        }
        // int star2 = i-1;
        // while(star2>0){
        //     cout << "* ";
        //     star2--;
        // }

        int k = n - i + 1;
        while (k > 0) {
            cout << k << " ";
            k--;
        }

        cout << endl;
        i++;
    }
}
void pattern23(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if ((i + j) % 2 == 0)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << '\n';
    }
}
void pattern24(int n) {
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        for (int j = 1; j <= 2 * n - 2 * i; j++) {
            cout << " ";
            // cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern25(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        char ch = 'A';

        int breakPoint = (2 * i - 1) / 2;

        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << ch << " ";
            if (j <= breakPoint)
                ch++;
            else
                ch--;
        }

        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern26(int n) {
    int initialSpace = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << '*';
        }
        for (int j = 0; j < initialSpace; j++) {
            cout << " ";
        }
        for (int j = 1; j <= n - i; j++) {
            cout << '*';
        }
        initialSpace += 2;
        cout << endl;
    }
    initialSpace = 2 * (n - 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << '*';
        }
        for (int j = 0; j < initialSpace; j++) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            cout << '*';
        }
        initialSpace -= 2;
        cout << endl;
    }
}
void pattern27(int n) {
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++) {

        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
            cout << "*";

        for (int j = 1; j <= spaces; j++)
            cout << " ";

        for (int j = 1; j <= stars; j++)
            cout << "*";

        cout << endl;
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}
void pattern28(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
int main() {
    // Your code goes here
    int n;
    cin >> n;
    pattern27(n);
    return 0;
}