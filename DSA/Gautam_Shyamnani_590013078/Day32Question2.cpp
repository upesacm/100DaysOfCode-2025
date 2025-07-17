#include <iostream>
#include <vector>
using namespace std;

int main() {
   
    vector<int> arr = {5, 1, 1, 5, 7};

    
    int result = 0;

    
    for (int num : arr) {
        result ^= num;  
    }
    cout << "The non-repeating element is: " << result << endl;

    return 0;
}
