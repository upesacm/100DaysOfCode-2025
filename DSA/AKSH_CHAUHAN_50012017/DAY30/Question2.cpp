#include <iostream>
using namespace std;

int toggleIthBit(int n, int i) {
    return n ^ (1 << i);
}
