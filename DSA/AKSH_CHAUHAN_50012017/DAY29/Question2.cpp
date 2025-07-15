#include <iostream>
using namespace std;

int getIthBit(int n, int i) {
    return (n >> i) & 1;
}
