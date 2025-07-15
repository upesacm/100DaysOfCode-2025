#include <iostream>
using namespace std;
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); 
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number (n): ";
    cin >> n;
    int result = countSetBits(n);
    cout << "Number of set bits: " << result << endl;
    return 0;
}
