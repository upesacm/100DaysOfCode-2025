import java.util.*;

public class TaskScheduling {
    public static int removeMinTasks(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));
        int count = 1;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= lastEnd) {
                count++;
                lastEnd = intervals[i][1];
            }
        }
        return intervals.length - count; // tasks removed
    }

    public static void main(String[] args) {
        int[][] tasks1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
        System.out.println("Remove " + removeMinTasks(tasks1)); // 1

        int[][] tasks2 = {{1, 2}, {1, 2}, {1, 2}};
        System.out.println("Remove " + removeMinTasks(tasks2)); // 2
    }
}
