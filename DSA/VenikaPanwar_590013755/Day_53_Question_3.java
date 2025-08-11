public class LongestMountain {
    public static int longestMountain(int[] arr) {
        int n = arr.length, longest = 0;

        for (int i = 1; i < n - 1; i++) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1, right = i + 1;

                while (left > 0 && arr[left - 1] < arr[left]) left--;
                while (right < n - 1 && arr[right] > arr[right + 1]) right++;

                longest = Math.max(longest, right - left + 1);
            }
        }

        return longest;
    }

    public static void main(String[] args) {
        System.out.println(longestMountain(new int[]{2, 1, 4, 7, 3, 2, 5})); // 5
        System.out.println(longestMountain(new int[]{2, 2, 2}));             // 0
    }
}
