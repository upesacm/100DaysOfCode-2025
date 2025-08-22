import java.util.*;

public class Question3 {

    // Function to compute minimum intervals to remove and return remaining count
    public static int[] eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) return new int[]{0, 0};

        // Sort intervals by their end time
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

        int count = 0; // intervals removed
        int kept = 1;  // at least 1 interval is kept
        int[] prev = intervals[0];

        for (int i = 1; i < intervals.length; i++) {
            int[] curr = intervals[i];
            if (prev[1] > curr[0]) {
                // Overlap → remove current
                count++;
            } else {
                // No overlap → keep it
                prev = curr;
                kept++;
            }
        }

        return new int[]{count, kept};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number of intervals
        System.out.print("Enter number of intervals: ");
        int n = sc.nextInt();

        int[][] intervals = new int[n][2];

        // Input intervals
        System.out.println("Enter intervals (start end):");
        for (int i = 0; i < n; i++) {
            intervals[i][0] = sc.nextInt();
            intervals[i][1] = sc.nextInt();
        }

        // Get result
        int[] result = eraseOverlapIntervals(intervals);

        // Output like example
        System.out.println("Remove " + result[0] + " -> Remaining " + result[1]);

        sc.close();
    }
}
