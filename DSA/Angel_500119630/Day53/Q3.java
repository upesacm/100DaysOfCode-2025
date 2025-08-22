public class Q3 {
    public static void main(String[] args) {
        int[] arr = {2, 1, 4, 7, 3, 2, 5};
        System.out.println(longestMountain(arr));
    }

    public static int longestMountain(int[] arr) {
        int n = arr.length, max = 0, i = 1;
        while (i < n - 1) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i, right = i;
                while (left > 0 && arr[left - 1] < arr[left]) left--;
                while (right < n - 1 && arr[right] > arr[right + 1]) right++;
                max = Math.max(max, right - left + 1);
                i = right;
            } else {
                i++;
            }
        }
        return max;
    }
}
