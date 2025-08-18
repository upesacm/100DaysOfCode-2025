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
    
    // Find maximum deadline to determine time slots
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    // Create time slots array (1-indexed, slot[i] represents time slot i)
    vector<bool> slot(maxDeadline + 1, false);
    int totalProfit = 0;
    int jobCount = 0;
    
    // For each job (sorted by profit)
    for (const Job& job : jobs) {
        // Find a free slot for this job (latest possible slot before deadline)
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

// Alternative function that returns both count and profit
pair<int, int> jobSchedulingWithCount(vector<Job>& jobs) {
    int n = jobs.size();
    if (n == 0) return {0, 0};
    
    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });
    
    // Find maximum deadline to determine time slots
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    // Create time slots array (1-indexed, slot[i] represents time slot i)
    vector<bool> slot(maxDeadline + 1, false);
    int totalProfit = 0;
    int jobCount = 0;
    
    // For each job (sorted by profit)
    for (const Job& job : jobs) {
        // Find a free slot for this job (latest possible slot before deadline)
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
