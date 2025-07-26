#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int findCelebrity(vector<vector<int>>& M) {
    int n = M.size();
    stack<int> s;
    
    for (int i = 0; i < n; ++i) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        
        if (M[a][b] == 1) {
            s.push(b);  // a knows b => a can't be celebrity
        } else {
            s.push(a);  // a doesn't know b => b can't be celebrity
        }
    }

    if (s.empty()) return -1;

    int c = s.top(); s.pop();

    for (int i = 0; i < n; ++i) {
        if (i != c && (M[c][i] == 1 || M[i][c] == 0)) {
            return -1;  // c knows someone OR someone doesn't know c
        }
    }

    return c;
}

int main() {
    vector<vector<int>> M1 = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    vector<vector<int>> M2 = {
        {0, 1},
        {1, 0}
    };

    cout << findCelebrity(M1) << endl; // Expected output: 2
    cout << findCelebrity(M2) << endl; // Expected output: -1

    return 0;
}
