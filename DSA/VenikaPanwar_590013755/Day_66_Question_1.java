import java.util.*;

public class MinPlatforms {
    public static int findPlatforms(int[] arr, int[] dep) {
        Arrays.sort(arr);
        Arrays.sort(dep);

        int n = arr.length;
        int i = 0, j = 0;
        int platforms = 0, maxPlatforms = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {   // train arrives
                platforms++;
                maxPlatforms = Math.max(maxPlatforms, platforms);
                i++;
            } else {                 // train departs
                platforms--;
                j++;
            }
        }
        return maxPlatforms;
    }

    public static void main(String[] args) {
        int[] arr1 = {900, 940, 950, 1100, 1500, 1800};
        int[] dep1 = {910, 1200, 1120, 1130, 1900, 2000};
        System.out.println(findPlatforms(arr1, dep1)); // 3

        int[] arr2 = {100, 200, 300};
        int[] dep2 = {150, 250, 350};
        System.out.println(findPlatforms(arr2, dep2)); // 1
    }
}
