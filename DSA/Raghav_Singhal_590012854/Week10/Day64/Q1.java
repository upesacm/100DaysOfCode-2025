import java.util.Arrays;

public class Q1 {
    public static void main(String[] args) 
    {
        int start[] = {1, 3, 0, 5, 8, 5};
        int end[] = {2, 4, 6, 7, 9, 9};
        System.out.println(bestSche(start,end));
    }
    public static int bestSche(int[]s,int[]e)
    {
        int n = s.length;
        int[][] activities = new int[n][2];
        for (int i = 0; i < n; i++) {
            activities[i][0] = s[i];
            activities[i][1] = e[i];
        }

        Arrays.sort(activities, (a, b) -> a[1] - b[1]);
        int count = 1; 
        int lastEnd = activities[0][1];
        for (int i = 1; i < n; i++) {
            if (activities[i][0] >= lastEnd) {
                count++;
                lastEnd = activities[i][1];
            }
        }
        return count;
    }
}
