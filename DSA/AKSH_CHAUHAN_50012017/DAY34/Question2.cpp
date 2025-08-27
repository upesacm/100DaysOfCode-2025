#include <iostream>
using namespace std;

int subtractOne(int n) {
    int mask = 1;
    while ((n & mask) == 0) {
        n = n ^ mask;
        mask <<= 1;
    }
    n = n ^ mask;
    return n;
}
