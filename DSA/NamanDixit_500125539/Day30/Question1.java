import java.util.*;

public class Question1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take integer input
        System.out.print("Enter the number: ");
        int i = sc.nextInt();

        // Take bit position input
        System.out.print("Enter the bit position to clear: ");
        int n = sc.nextInt();

        // Create bitmask by left shifting 1 by n
        int mask = 1 << n;

        // Clear the bit at position n
        int result = i & ~mask;

        // Output the result
        System.out.println(result);

        sc.close();
    }
}
