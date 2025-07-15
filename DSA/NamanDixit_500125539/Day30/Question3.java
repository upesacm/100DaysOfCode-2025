import java.util.*;

public class Question3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take integer input
        System.out.print("Enter the number: ");
        int n = sc.nextInt();

        // Count set bits using Brian Kernighan’s Algorithm
        int count = 0;
        while (n > 0) {
            n = n & (n - 1); // Clear the least significant bit set
            count++;
        }

        // Output the result
        System.out.println(count);

        sc.close();
    }
}
