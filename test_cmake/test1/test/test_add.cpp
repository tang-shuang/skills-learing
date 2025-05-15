#include "../mylib.h"
#include <iostream>

int main() {
    if (add(2, 3) != 5) {
        std::cerr << "Test failed: add(2, 3) != 5" << std::endl;
        return 1; // 表示失败
    }
    if (add(0, 0) != 0) {
        std::cerr << "Test failed: add(0, 0) != 0" << std::endl;
        return 1;
    }
    std::cout << "All tests passed!" << std::endl;
    return 0; // 表示成功
}

