import java.util.Scanner;

public class AddOneBitwise {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number to add 1: ");
        int n = sc.nextInt();

        int mask = 1;

        while ((n & mask) != 0) {
            n = n ^ mask;    // toggle current bit from 1 to 0
            mask <<= 1;      // move to next higher bit
        }

        n = n ^ mask;        // set first 0 bit to 1 (carry ends here)

        System.out.println("Result: " + n);
    }
}
