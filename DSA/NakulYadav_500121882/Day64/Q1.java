import java.util.*;
public class Q1 {
    public static void main(String[] args) {
        int[] start = {1,3,0,5,8,5};
        int[] end = {2,4,6,7,9,9};
        int n = start.length;
        int[][] acts = new int[n][2];
        for (int i = 0; i < n; i++) acts[i] = new int[]{start[i], end[i]};
        Arrays.sort(acts, Comparator.comparingInt(a -> a[1]));
        int count = 1, last = acts[0][1];
        for (int i = 1; i < n; i++) 
            if (acts[i][0] >= last) { count++; last = acts[i][1]; }
        System.out.println(count);
    }
}
