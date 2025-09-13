#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prim(int V, vector<vector<pair<int,int>>>& adj) {
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 0});

    int cost = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        cost += w;

        for (auto [v, wt] : adj[u]) {
            if (!inMST[v]) pq.push({wt, v});
        }
    }
    return cost;
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);
    adj[0].push_back({1,2});
    adj[0].push_back({3,6});
    adj[1].push_back({0,2});
    adj[1].push_back({2,3});
    adj[1].push_back({3,8});
    adj[1].push_back({4,5});
    adj[2].push_back({1,3});
    adj[2].push_back({4,7});
    adj[3].push_back({0,6});
    adj[3].push_back({1,8});
    adj[3].push_back({4,9});
    adj[4].push_back({1,5});
    adj[4].push_back({2,7});
    adj[4].push_back({3,9});

    cout << "MST Cost (Prim): " << prim(V, adj) << endl;
    return 0;
}
