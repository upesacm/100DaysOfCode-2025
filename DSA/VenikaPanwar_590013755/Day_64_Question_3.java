import java.util.*;

class Job {
    int id, deadline, profit;
    Job(int i, int d, int p) { id = i; deadline = d; profit = p; }
}

public class JobScheduling {
    public static int[] jobScheduling(Job[] jobs) {
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        int maxDeadline = 0;
        for (Job job : jobs) maxDeadline = Math.max(maxDeadline, job.deadline);

        int[] slot = new int[maxDeadline + 1];
        Arrays.fill(slot, -1);

        int countJobs = 0, totalProfit = 0;

        for (Job job : jobs) {
            for (int t = job.deadline; t > 0; t--) {
                if (slot[t] == -1) {
                    slot[t] = job.id;
                    countJobs++;
                    totalProfit += job.profit;
                    break;
                }
            }
        }
        return new int[]{countJobs, totalProfit};
    }

    public static void main(String[] args) {
        Job[] jobs1 = { new Job(1, 4, 20), new Job(2, 1, 10), new Job(3, 1, 40), new Job(4, 1, 30) };
        int[] res1 = jobScheduling(jobs1);
        System.out.println(res1[0] + " jobs, Profit: " + res1[1]); // 2 jobs, Profit: 60

        Job[] jobs2 = { new Job(1, 2, 100), new Job(2, 1, 19), new Job(3, 2, 27) };
        int[] res2 = jobScheduling(jobs2);
        System.out.println(res2[0] + " jobs, Profit: " + res2[1]); // 2 jobs, Profit: 127
    }
}
