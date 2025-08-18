#include <vector>
#include <algorithm>
using namespace std;
struct Job {
    int id;
    int deadline;
    int profit;
};
int jobScheduling(vector<Job>& jobs) {
    int n = jobs.size();
    if (n == 0) return 0;
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    vector<bool> slot(maxDeadline + 1, false);
    int totalProfit = 0;
    int jobCount = 0;
    for (const Job& job : jobs) {
        for (int j = job.deadline; j >= 1; j--) {
            if (!slot[j]) {
                slot[j] = true;
                totalProfit += job.profit;
                jobCount++;
                break;
            }
        }
    }
    return totalProfit;
}
pair<int, int> jobSchedulingWithCount(vector<Job>& jobs) {
    int n = jobs.size();
    if (n == 0) return {0, 0};
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    vector<bool> slot(maxDeadline + 1, false);
    int totalProfit = 0;
    int jobCount = 0;
    for (const Job& job : jobs) {
        for (int j = job.deadline; j >= 1; j--) {
            if (!slot[j]) {
                slot[j] = true;
                totalProfit += job.profit;
                jobCount++;
                break;
            }
        }
    }
    return {jobCount, totalProfit};
}