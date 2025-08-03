import java.util.*;

public class Day_30_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number (n): ");
        int n = sc.nextInt();
        System.out.print("Enter bit position to clear (i): ");
        int i = sc.nextInt();

        if (i < 0 || i >= 32) {
            System.out.println("Invalid bit position.");
            return;
        }

        int mask = ~(1 << i);
        int result = n & mask;

        System.out.println("Result after clearing bit " + i + ": " + result);
    }
}
