
import java.util.*;

public class Question3 {

    // Class to represent a job
    static class Job {

        int start, duration, profit, end;

        Job(int start, int duration, int profit) {
            this.start = start;
            this.duration = duration;
            this.profit = profit;
            this.end = start + duration; // calculate end time
        }
    }

    // Binary search to find the latest non-conflicting job
    private static int findLatestNonConflict(Job[] jobs, int index) {
        int low = 0, high = index - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid].end <= jobs[index].start) {
                if (mid + 1 <= high && jobs[mid + 1].end <= jobs[index].start) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    // Compute maximum profit and track chosen jobs
    public static List<Job> maxProfit(Job[] jobs) {
        int n = jobs.length;

        // Sort jobs by end time
        Arrays.sort(jobs, Comparator.comparingInt(j -> j.end));

        // dp[i] = maximum profit including jobs[0..i]
        int[] dp = new int[n];
        // store the index chosen for reconstruction
        int[] chosen = new int[n];

        dp[0] = jobs[0].profit;
        chosen[0] = -1;

        for (int i = 1; i < n; i++) {
            int inclProfit = jobs[i].profit;
            int l = findLatestNonConflict(jobs, i);
            if (l != -1) {
                inclProfit += dp[l];
            }

            if (inclProfit > dp[i - 1]) {
                dp[i] = inclProfit;
                chosen[i] = l; // store link to previous compatible job
            } else {
                dp[i] = dp[i - 1];
                chosen[i] = chosen[i - 1]; // carry forward
            }
        }

        // Backtrack to find selected jobs
        List<Job> selected = new ArrayList<>();
        int i = n - 1;
        int maxProfit = dp[n - 1];

        while (i >= 0) {
            int l = findLatestNonConflict(jobs, i);
            int inclProfit = jobs[i].profit + (l != -1 ? dp[l] : 0);

            if (inclProfit == maxProfit) {
                selected.add(jobs[i]);
                maxProfit -= jobs[i].profit;
                i = l;
            } else {
                i--;
            }
        }

        Collections.reverse(selected);
        return selected;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of jobs: ");
        int n = scanner.nextInt();

        Job[] jobs = new Job[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter start time for job " + (i + 1) + ": ");
            int start = scanner.nextInt();
            System.out.print("Enter duration for job " + (i + 1) + ": ");
            int duration = scanner.nextInt();
            System.out.print("Enter profit for job " + (i + 1) + ": ");
            int profit = scanner.nextInt();

            jobs[i] = new Job(start, duration, profit);
        }
        scanner.close();

        List<Job> selectedJobs = maxProfit(jobs);
        int totalProfit = selectedJobs.stream().mapToInt(j -> j.profit).sum();

        System.out.println(selectedJobs.size() + " jobs, Profit: " + totalProfit);
    }
}
