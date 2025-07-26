#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> s; 

    for (int i = 0; i < n; ++i) {
       
        while (!s.empty() && prices[s.top()] <= prices[i])
            s.pop();

        
        span[i] = (s.empty()) ? (i + 1) : (i - s.top());

        s.push(i);  
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = calculateSpan(prices);

    cout << "Stock spans: ";
    for (int s : span) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
