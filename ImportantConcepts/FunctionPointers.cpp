/**
 * Author: omteja04
 * Created on: 03-09-2024 19:55:03
 * Description: LambdaFunctions, FunctionPointers
 **/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// void helloWorld(int a) {
//     std::cout << "Hello World! Value : " << a << std::endl;
// }
// void printValue(int value) {
//     std::cout << "Value : " << value << std::endl;
// }
void forEach(const std::vector<int> &values, const std::function<void(int)> func) {
    for (int value : values) {
        func(value);
    }
}
void forEach(const std::vector<int> &values, void (*func)(int)) {
    for (int value : values) {
        func(value);
    }
}
int main() {
    // typedef void (*helloWorldFunction)(int);
    // helloWorldFunction function = helloWorld;
    // function(4);
    // function(2);
    // function(3);
    std::vector<int> values = {1, 6, 3, 5, 6, 4};
    std::vector<int>::iterator it = std::find_if(values.begin(), values.end(), [](int value) -> bool { return value > 3; });
    std::cout << *it << std::endl;
    // forEach(values, printValue);
    int a = 10;

    // function<return_type(param)>
    std::function<void(int)> lambda = [&](int value) {
        a = 10;
        std::cout << "Value : " << value + a << std::endl;
    };
    forEach(values, lambda);
}