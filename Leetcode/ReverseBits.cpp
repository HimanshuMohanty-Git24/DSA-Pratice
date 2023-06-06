#include <iostream>
#include <cstdint>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        if (n & 1) {
            result++;
        }
        n >>= 1;
    }
    return result;
}

int main() {
    uint32_t rev = reverseBits(0b00000010100101000001111010011100);
    cout << rev;
    return 0;
}
