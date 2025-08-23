#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); // removes the lowest set bit
        count++;
    }
    return count;
}
