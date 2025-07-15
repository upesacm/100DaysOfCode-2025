import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take integer input
        System.out.print("Enter the number: ");
        int i = sc.nextInt();

        // Take bit position input
        System.out.print("Enter the bit position to toggle: ");
        int n = sc.nextInt();

        // Toggle the bit at position n
        int result = i ^ (1 << n);

        // Output the result
        System.out.println(result);

        sc.close();
    }
}
