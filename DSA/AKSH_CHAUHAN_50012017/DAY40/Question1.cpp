#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Sample M matrix to store who knows whom
bool knows(vector<vector<int>> &M, int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(vector<vector<int>> &M, int n) {
    stack<int> s;

    // Push all people into the stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Eliminate non-celebrities
    while (s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();

        if (knows(M, a, b))
            s.push(b);  // a cannot be celebrity
        else
            s.push(a);  // b cannot be celebrity
    }

    int candidate = s.top();

    // Final check
    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(M, candidate, i) || !knows(M, i, candidate)))
            return -1;
    }

    return candidate;
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    int n = M.size();

    int celeb = findCelebrity(M, n);
    cout << "Celebrity Index: " << celeb << endl;
    return 0;
}
