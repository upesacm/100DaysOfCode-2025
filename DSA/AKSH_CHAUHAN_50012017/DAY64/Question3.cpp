#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit; // sort by descending profit
}

int jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int n = jobs.size();
    int maxDeadline = 0;
    for(auto &j : jobs) maxDeadline = max(maxDeadline, j.deadline);

    vector<int> slot(maxDeadline+1, -1);
    int countJobs = 0, totalProfit = 0;

    for(auto &j : jobs) {
        for(int d = j.deadline; d > 0; d--) {
            if(slot[d] == -1) {
                slot[d] = j.id;
                countJobs++;
                totalProfit += j.profit;
                break;
            }
        }
    }

    cout << countJobs << " jobs, Profit: " << totalProfit << endl;
    return totalProfit;
}

int main() {
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    jobScheduling(jobs);
    return 0;
}
