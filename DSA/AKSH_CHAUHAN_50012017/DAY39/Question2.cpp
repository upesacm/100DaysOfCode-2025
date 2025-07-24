#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculateSpan(vector<int> &prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && prices[i] >= prices[s.top()])
            s.pop();

        span[i] = (s.empty()) ? (i + 1) : (i - s.top());
        s.push(i);
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = calculateSpan(prices);

    cout << "Stock Spans: ";
    for (int val : span)
        cout << val << " ";
    cout << endl;

    return 0;
}
