
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    vector<int> cuts(n, 0);

    for (int i = 0; i < n; i++) {
        int minCuts = i; 
        for (int j = 0; j <= i; j++) {
            if (s[i] == s[j] && (i - j < 2 || isPal[j+1][i-1])) {
                isPal[j][i] = true;
                if (j == 0) minCuts = 0;
                else minCuts = min(minCuts, cuts[j-1] + 1);
            }
        }
        cuts[i] = minCuts;
    }
    return cuts[n-1];
}

int main() {
    string s = "aab";
    cout << "Minimum cuts for palindrome partitioning: " << minCut(s) << endl;
    return 0;
}
