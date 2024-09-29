/**
 * Author: omteja04
 * Created on: 03-09-2024 22:45:44
 * Description: RecursiveLambda
 **/

// A lambda cannot directly reference itself in its definition.
#include <functional>
#include <iostream>

int main() {
    // Using Functional Header
    std::function<int(int, int)> gcd = [&](int a, int b) -> int {
        return b == 0 ? a : gcd(b, a % b);
    };
    std::cout << gcd(5, 10) << std::endl;

    auto gcd2 = [&](int a, int b, auto &&gcd2) -> int {
        return b == 0 ? a : gcd2(b, a % b, gcd2);
    };

    std::cout << gcd2(5, 10, gcd2) << std::endl;
}