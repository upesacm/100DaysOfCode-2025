import java.util.*;

class Job {
    int id, deadline, profit;
    Job(int id, int deadline, int profit) {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
}

class DisjointSet {
    int[] parent;

    DisjointSet(int n) {
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void union(int x, int y) {
        parent[x] = y;
    }
}

public class Q3 {
    public static void main(String[] args) {
        Job[] jobs = {
            new Job(1, 4, 20),
            new Job(2, 1, 10),
            new Job(3, 1, 40),
            new Job(4, 1, 30)
        };

        int[] result = jobScheduling(jobs);
        System.out.println(result[0] + " jobs, Profit: " + result[1]);
    }

    public static int[] jobScheduling(Job[] jobs) {
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        int maxDeadline = 0;
        for (Job job : jobs) {
            maxDeadline = Math.max(maxDeadline, job.deadline);
        }

        DisjointSet ds = new DisjointSet(maxDeadline);

        int jobCount = 0, totalProfit = 0;

        for (Job job : jobs) {
            int availableSlot = ds.find(job.deadline);

            if (availableSlot > 0) {
                jobCount++;
                totalProfit += job.profit;

                ds.union(availableSlot, availableSlot - 1);
            }
        }

        return new int[]{jobCount, totalProfit};
    }
}
