import java.util.*;

public class SubtractOneBitwise {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number to subtract 1: ");
        int n = sc.nextInt();

        int mask = 1;

        while ((n & mask) == 0) {
            n = n ^ mask;    // flip 0 to 1 to handle borrow
            mask <<= 1;
        }

        n = n ^ mask;        // flip the first 1 to 0

        System.out.println("Result: " + n);
    }
}
