#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);  
        count++;          
    }
    return count;
}

int main() {
    cout << countSetBits(7) << endl;  
    cout << countSetBits(9) << endl;  
    return 0;
}
