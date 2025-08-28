import java.util.Arrays;
import java.util.Scanner;

public class Q1 {
    public static int findMinimumPlatforms(int[] arrival, int[] departure, int n) {
        Arrays.sort(arrival);
        Arrays.sort(departure);

        int platforms = 1, maxPlatforms = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arrival[i] <= departure[j]) {
                platforms++;
                i++;
                maxPlatforms = Math.max(maxPlatforms, platforms);
            } else {
                platforms--;
                j++;
            }
        }
        return maxPlatforms;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arrival = new int[n];
        int[] departure = new int[n];

        for (int i = 0; i < n; i++) {
            arrival[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            departure[i] = sc.nextInt();
        }

        System.out.println(findMinimumPlatforms(arrival, departure, n));
        sc.close();
    }
}
