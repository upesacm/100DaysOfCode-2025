public class SmallestSubarrayWithSum {
    public static int smallestSubarray(int[] arr, int x) {
        int n = arr.length, minLen = Integer.MAX_VALUE;
        int sum = 0, left = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > x) {
                minLen = Math.min(minLen, right - left + 1);
                sum -= arr[left++];
            }
        }

        return (minLen == Integer.MAX_VALUE) ? 0 : minLen;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 4, 45, 6, 0, 19};
        int x1 = 51;
        System.out.println("Output 1: " + smallestSubarray(arr1, x1)); // 3

        int[] arr2 = {1, 10, 5, 2, 7};
        int x2 = 9;
        System.out.println("Output 2: " + smallestSubarray(arr2, x2)); // 1
    }
}
