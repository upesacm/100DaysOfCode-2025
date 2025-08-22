import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Question1 {

    // Function to perform activity selection
    public static int activitySelection(int[] start, int[] end) {
        int n = start.length;
        Activity[] activities = new Activity[n];

        for (int i = 0; i < n; i++) {
            activities[i] = new Activity(start[i], end[i]);
        }

        // Sort activities by their finish time
        Arrays.sort(activities, Comparator.comparingInt(a -> a.end));

        // First activity is always selected
        int count = 1;
        int lastSelected = 0;

        // Iterate through sorted activities
        for (int i = 1; i < n; i++) {
            if (activities[i].start >= activities[lastSelected].end) {
                count++;
                lastSelected = i;
            }
        }

        return count; // return number of activities selected
    }

    // Activity class to store start and end times
    static class Activity {
        int start, end;
        Activity(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take number of activities as input
        System.out.print("Enter the number of activities: ");
        int n = scanner.nextInt();

        int[] startTimes = new int[n];
        int[] endTimes = new int[n];

        // Input start and end times
        for (int i = 0; i < n; i++) {
            System.out.print("Enter start time for activity " + (i + 1) + ": ");
            startTimes[i] = scanner.nextInt();
            System.out.print("Enter end time for activity " + (i + 1) + ": ");
            endTimes[i] = scanner.nextInt();
        }

        // Get result
        int result = activitySelection(startTimes, endTimes);

        // Print the maximum number of activities
        System.out.println(result);

        scanner.close();
    }
}
