#include <iostream>
using namespace std;

int addOne(int n) {
    int mask = 1;
    while (n & mask) {
        n = n ^ mask;
        mask <<= 1;
    }
    n = n ^ mask;
    return n;
}
