#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> generateBinary(int n) {
    vector<string> result;
    queue<string> q;

    
    q.push("1");

    for (int i = 0; i < n; ++i) {
        string current = q.front();
        q.pop();

        
        result.push_back(current);

        
        q.push(current + "0");
        q.push(current + "1");
    }

    return result;
}

int main() {
    int n = 5;
    vector<string> binaryNumbers = generateBinary(n);

    cout << "Binary numbers from 1 to " << n << ": ";
    for (const string& num : binaryNumbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
