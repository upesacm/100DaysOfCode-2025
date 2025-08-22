import java.util.*;

public class Day_68_Question_3 {
    
    /**
     * Inner class to represent a meeting with start time, end time, and original index
     */
    static class Meeting {
        int startTime;
        int endTime;
        int originalIndex;
        
        Meeting(int start, int end, int index) {
            this.startTime = start;
            this.endTime = end;
            this.originalIndex = index;
        }
        
        @Override
        public String toString() {
            return "Meeting[" + originalIndex + "]: (" + startTime + ", " + endTime + ")";
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of meetings: ");
        int n = scanner.nextInt();
        
        int[] startTimes = new int[n];
        int[] endTimes = new int[n];
        
        System.out.println("Enter start times:");
        for (int i = 0; i < n; i++) {
            startTimes[i] = scanner.nextInt();
        }
        
        System.out.println("Enter end times:");
        for (int i = 0; i < n; i++) {
            endTimes[i] = scanner.nextInt();
        }
        
        int maxMeetings = findMaxNonOverlappingMeetings(startTimes, endTimes);
        System.out.println("Maximum number of non-overlapping meetings: " + maxMeetings);
        
        // Show detailed selection process
        List<Integer> selectedMeetingIndices = getSelectedMeetingIndices(startTimes, endTimes);
        System.out.print("Selected meeting indices: ");
        for (int index : selectedMeetingIndices) {
            System.out.print(index + " ");
        }
        System.out.println();
        
        // Demonstrate with examples
        demonstrateExamples();
        
        scanner.close();
    }
    
    /**
     * Finds maximum number of non-overlapping meetings using earliest finish time greedy strategy
     * This approach maximizes the number of meetings by always selecting the meeting that ends earliest
     */
    public static int findMaxNonOverlappingMeetings(int[] start, int[] end) {
        int n = start.length;
        
        if (n == 0) return 0;
        
        // Create meeting objects for easier manipulation
        Meeting[] meetings = new Meeting[n];
        for (int i = 0; i < n; i++) {
            meetings[i] = new Meeting(start[i], end[i], i);
        }
        
        // Sort meetings by end time (earliest finish time first)
        Arrays.sort(meetings, new Comparator<Meeting>() {
            @Override
            public int compare(Meeting first, Meeting second) {
                if (first.endTime != second.endTime) {
                    return Integer.compare(first.endTime, second.endTime);
                }
                // If end times are equal, prefer meeting with earlier start time
                return Integer.compare(first.startTime, second.startTime);
            }
        });
        
        int meetingCount = 0;
        int lastEndTime = -1;
        
        // Greedily select meetings that don't overlap
        for (Meeting currentMeeting : meetings) {
            // If current meeting starts after the last selected meeting ends
            if (currentMeeting.startTime >= lastEndTime) {
                meetingCount++;
                lastEndTime = currentMeeting.endTime;
            }
        }
        
        return meetingCount;
    }
    
    /**
     * Returns the indices of selected meetings for detailed analysis
     */
    public static List<Integer> getSelectedMeetingIndices(int[] start, int[] end) {
        int n = start.length;
        List<Integer> selectedIndices = new ArrayList<>();
        
        if (n == 0) return selectedIndices;
        
        Meeting[] meetings = new Meeting[n];
        for (int i = 0; i < n; i++) {
            meetings[i] = new Meeting(start[i], end[i], i);
        }
        
        // Sort by end time using lambda expression
        Arrays.sort(meetings, (a, b) -> {
            if (a.endTime != b.endTime) return Integer.compare(a.endTime, b.endTime);
            return Integer.compare(a.startTime, b.startTime);
        });
        
        int lastEndTime = -1;
        
        for (Meeting meeting : meetings) {
            if (meeting.startTime >= lastEndTime) {
                selectedIndices.add(meeting.originalIndex);
                lastEndTime = meeting.endTime;
            }
        }
        
        // Sort indices for better presentation
        Collections.sort(selectedIndices);
        return selectedIndices;
    }
    
    /**
     * Alternative implementation without custom class
     */
    public static int findMaxMeetingsSimple(int[] start, int[] end) {
        int n = start.length;
        if (n == 0) return 0;
        
        // Create array of indices
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        
        // Sort indices based on end times
        Arrays.sort(indices, (i, j) -> {
            if (end[i] != end[j]) return Integer.compare(end[i], end[j]);
            return Integer.compare(start[i], start[j]);
        });
        
        int count = 1; // First meeting is always selected
        int lastEnd = end[indices[0]];
        
        for (int i = 1; i < n; i++) {
            int currentIndex = indices[i];
            if (start[currentIndex] >= lastEnd) {
                count++;
                lastEnd = end[currentIndex];
            }
        }
        
        return count;
    }
    
    /**
     * Demonstrates the selection process with detailed output
     */
    public static void demonstrateSelectionProcess(int[] start, int[] end) {
        System.out.println("\n--- Meeting Selection Process ---");
        
        int n = start.length;
        Meeting[] meetings = new Meeting[n];
        for (int i = 0; i < n; i++) {
            meetings[i] = new Meeting(start[i], end[i], i);
        }
        
        Arrays.sort(meetings, (a, b) -> {
            if (a.endTime != b.endTime) return Integer.compare(a.endTime, b.endTime);
            return Integer.compare(a.startTime, b.startTime);
        });
        
        System.out.println("Meetings sorted by end time:");
        for (Meeting meeting : meetings) {
            System.out.println(meeting);
        }
        
        int lastEndTime = -1;
        System.out.println("\nSelection process:");
        
        for (Meeting meeting : meetings) {
            if (meeting.startTime >= lastEndTime) {
                System.out.println("Selected: " + meeting);
                lastEndTime = meeting.endTime;
            } else {
                System.out.println("Rejected: " + meeting + " (overlaps with previous)");
            }
        }
    }
    
    /**
     * Demonstrates the algorithm with provided examples
     */
    public static void demonstrateExamples() {
        System.out.println("\n--- Example Demonstrations ---");
        
        // Example: start = [1, 3, 0, 5, 8, 5], end = [2, 4, 6, 7, 9, 9] -> 4
        int[] exampleStart = {1, 3, 0, 5, 8, 5};
        int[] exampleEnd = {2, 4, 6, 7, 9, 9};
        int result = findMaxNonOverlappingMeetings(exampleStart, exampleEnd);
        
        System.out.println("Example: start = [1, 3, 0, 5, 8, 5], end = [2, 4, 6, 7, 9, 9]");
        System.out.println("Maximum non-overlapping meetings: " + result);
        
        demonstrateSelectionProcess(exampleStart, exampleEnd);
    }
}
