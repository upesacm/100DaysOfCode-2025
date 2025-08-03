import java.util.*;

public class Day_30_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number (n): ");
        int n = sc.nextInt();
        System.out.print("Enter bit position to toggle (i): ");
        int i = sc.nextInt();

        if (i < 0 || i >= 32) {
            System.out.println("Invalid bit position.");
            return;
        }

        int result = n ^ (1 << i);

        System.out.println("Result after toggling bit " + i + ": " + result);
    }
}
