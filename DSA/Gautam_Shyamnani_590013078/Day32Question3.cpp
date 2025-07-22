#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {4, 5, 6};

   
    int xorResult = 0;
    for (int num : arr) {
        xorResult ^= num;
    }

    cout << "The XOR of all numbers is: " << xorResult << endl;

    return 0;
}
