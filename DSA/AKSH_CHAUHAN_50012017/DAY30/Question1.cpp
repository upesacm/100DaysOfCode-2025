#include <iostream>
using namespace std;

int clearIthBit(int n, int i) {
    return n & ~(1 << i);
}
