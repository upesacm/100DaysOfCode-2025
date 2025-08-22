import java.util.*;

public class Question1 {

    // Function to find minimum number of platforms required
    public static int findMinPlatforms(int[] arr, int[] dep, int n) {
        // Sort both arrays
        Arrays.sort(arr);
        Arrays.sort(dep);

        int platformsNeeded = 0, maxPlatforms = 0;
        int i = 0, j = 0;

        // Process events in chronological order
        while (i < n && j < n) {
            // If next event is arrival -> add a platform
            if (arr[i] <= dep[j]) {
                platformsNeeded++;
                maxPlatforms = Math.max(maxPlatforms, platformsNeeded);
                i++;
            }
            // If next event is departure -> free a platform
            else {
                platformsNeeded--;
                j++;
            }
        }
        return maxPlatforms;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of trains: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        int[] dep = new int[n];

        System.out.println("Enter arrival times (e.g., 900 for 9:00 AM):");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Enter departure times (e.g., 1130 for 11:30 AM):");
        for (int i = 0; i < n; i++) {
            dep[i] = sc.nextInt();
        }

        sc.close();

        int result = findMinPlatforms(arr, dep, n);
        System.out.println("Minimum Platforms Required: " + result);
    }
}
