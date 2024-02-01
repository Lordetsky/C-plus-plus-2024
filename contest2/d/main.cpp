#include <iostream>
#include <bitset>

int main() {
    std::bitset<32> n(2);
    std::cout << n << '\n' << n[1];

    return 0;
}
