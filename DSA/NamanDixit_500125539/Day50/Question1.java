import java.util.Scanner;

public class Question1 {

    static int maxSumSubArray(int[] a, int k) {
        int wSum = 0;
        int mSum = Integer.MIN_VALUE;

        for (int i = 0; i < k; i++) {
            wSum += a[i];
        }

        mSum = wSum;

        for (int i = k; i < a.length; i++) {
            wSum = wSum - a[i - k] + a[i];
            mSum = Math.max(mSum, wSum);
        }

        return mSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] a = new int[n];
        System.out.println("Enter elements of array:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        System.out.print("Enter window size k: ");
        int k = sc.nextInt();

        if (k > n) {
            System.out.println("Window size k should be less than or equal to array size.");
        } else {
            int result = maxSumSubArray(a, k);
            System.out.println(result);
        }

        sc.close();
    }
}
