#include <iostream>
using namespace std;

int setIthBit(int n, int i) {
    return n | (1 << i);
}
