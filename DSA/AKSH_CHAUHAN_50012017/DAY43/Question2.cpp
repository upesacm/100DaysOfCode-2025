#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> generateBinary(int n) {
    vector<string> result;
    queue<string> q;

    q.push("1");
    while (n--) {
        string curr = q.front();
        q.pop();
        result.push_back(curr);
        q.push(curr + "0");
        q.push(curr + "1");
    }

    return result;
}

int main() {
    int n = 5;
    vector<string> res = generateBinary(n);

    cout << "Binary Numbers: ";
    for (string s : res)
        cout << s << " ";
    cout << endl;
    return 0;
}
