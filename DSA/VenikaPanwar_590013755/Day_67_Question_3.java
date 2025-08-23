import java.util.*;

public class Day_67_Question_3 {
    // Class to represent a meeting with start and end times
    static class Meeting {
        int start;
        int end;
        int index; // For tracking original position
        
        Meeting(int start, int end, int index) {
            this.start = start;
            this.end = end;
            this.index = index;
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of meetings: ");
        int n = scanner.nextInt();
        
        int[] start = new int[n];
        int[] end = new int[n];
        
        System.out.println("Enter start times:");
        for (int i = 0; i < n; i++) {
            start[i] = scanner.nextInt();
        }
        
        System.out.println("Enter end times:");
        for (int i = 0; i < n; i++) {
            end[i] = scanner.nextInt();
        }
        
        int maxMeetings = findMaxMeetings(start, end);
        System.out.println("Maximum number of non-overlapping meetings: " + maxMeetings);
        
        // Also show which meetings are selected
        List<Integer> selectedMeetings = findSelectedMeetings(start, end);
        System.out.print("Selected meeting indices: ");
        for (int i : selectedMeetings) {
            System.out.print(i + " ");
        }
        System.out.println();
        
        scanner.close();
    }
    
    public static int findMaxMeetings(int[] start, int[] end) {
        int n = start.length;
        
        // Create meeting objects
        Meeting[] meetings = new Meeting[n];
        for (int i = 0; i < n; i++) {
            meetings[i] = new Meeting(start[i], end[i], i);
        }
        
        // Sort meetings by end time (greedy approach)
        Arrays.sort(meetings, new Comparator<Meeting>() {
            @Override
            public int compare(Meeting a, Meeting b) {
                if (a.end != b.end) {
                    return Integer.compare(a.end, b.end);
                }
                // If end times are same, prefer meeting with earlier start
                return Integer.compare(a.start, b.start);
            }
        });
        
        int count = 0;
        int lastEndTime = -1;
        
        // Select meetings greedily
        for (Meeting meeting : meetings) {
            if (meeting.start >= lastEndTime) {
                count++;
                lastEndTime = meeting.end;
            }
        }
        
        return count;
    }
    
    // Method to return the actual selected meeting indices
    public static List<Integer> findSelectedMeetings(int[] start, int[] end) {
        int n = start.length;
        List<Integer> selectedMeetings = new ArrayList<>();
        
        Meeting[] meetings = new Meeting[n];
        for (int i = 0; i < n; i++) {
            meetings[i] = new Meeting(start[i], end[i], i);
        }
        
        // Sort by end time with lambda expression
        Arrays.sort(meetings, (a, b) -> {
            if (a.end != b.end) return Integer.compare(a.end, b.end);
            return Integer.compare(a.start, b.start);
        });
        
        int lastEndTime = -1;
        
        for (Meeting meeting : meetings) {
            if (meeting.start >= lastEndTime) {
                selectedMeetings.add(meeting.index);
                lastEndTime = meeting.end;
            }
        }
        
        // Sort the selected indices for better presentation
        Collections.sort(selectedMeetings);
        return selectedMeetings;
    }
    
    // Simple version without tracking indices
    public static int findMaxMeetingsSimple(int[] start, int[] end) {
        int n = start.length;
        
        // Create array of indices and sort by end time
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        
        Arrays.sort(indices, (i, j) -> Integer.compare(end[i], end[j]));
        
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
}
