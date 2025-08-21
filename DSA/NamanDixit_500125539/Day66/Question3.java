import java.util.*;

public class Question3 {

    // Function to calculate the minimum candies required
    public static int candy(int[] ratings) {
        int n = ratings.length;
        int[] ans = new int[n];
        Arrays.fill(ans, 1); // each child gets at least 1 candy

        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                ans[i] = ans[i - 1] + 1;
            }
        }

        // Right to left pass
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i] < ratings[i - 1] && ans[i] >= ans[i - 1]) {
                ans[i - 1] = ans[i] + 1;
            }
        }

        // Sum of all candies
        return Arrays.stream(ans).sum();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of children: ");
        int n = sc.nextInt();

        int[] ratings = new int[n];
        System.out.println("Enter ratings of children:");
        for (int i = 0; i < n; i++) {
            ratings[i] = sc.nextInt();
        }
        sc.close();

        int result = candy(ratings);
        System.out.println("Minimum number of candies required: " + result);
    }
}
