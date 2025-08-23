import java.util.*;

public class Question3{

    // Function to schedule maximum number of meetings
    public static int maxMeetings(int[] start, int[] end) {
        int n = start.length;
        Meeting[] meetings = new Meeting[n];

        // Store meetings with start and end time
        for (int i = 0; i < n; i++) {
            meetings[i] = new Meeting(start[i], end[i]);
        }

        // Sort meetings by earliest finish time
        Arrays.sort(meetings, Comparator.comparingInt(m -> m.end));

        int count = 1; // first meeting is always chosen
        int lastSelected = 0;

        // Greedy choice: pick next meeting that starts after last selected one ends
        for (int i = 1; i < n; i++) {
            if (meetings[i].start >= meetings[lastSelected].end) {
                count++;
                lastSelected = i;
            }
        }

        return count; // maximum number of non-overlapping meetings
    }

    // Meeting class
    static class Meeting {
        int start, end;
        Meeting(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of meetings: ");
        int n = scanner.nextInt();

        int[] start = new int[n];
        int[] end = new int[n];

        // Input start and end times
        for (int i = 0; i < n; i++) {
            System.out.print("Enter start time for meeting " + (i + 1) + ": ");
            start[i] = scanner.nextInt();
            System.out.print("Enter end time for meeting " + (i + 1) + ": ");
            end[i] = scanner.nextInt();
        }

        int result = maxMeetings(start, end);

        System.out.println("Maximum number of meetings that can be scheduled: " + result);

        scanner.close();
    }
}
