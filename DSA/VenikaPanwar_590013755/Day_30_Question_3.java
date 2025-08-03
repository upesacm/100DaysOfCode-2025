import java.util.*;

public class Day_30_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number (n): ");
        int n = sc.nextInt();

        if (n < 0) {
            System.out.println("Negative input not allowed.");
            return;
        }

        int count = 0;
        while (n > 0) {
            n = n & (n - 1);  // removes the lowest set bit
            count++;
        }

        System.out.println("Number of set bits: " + count);
    }
}
