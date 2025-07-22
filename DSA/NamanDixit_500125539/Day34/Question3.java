import java.util.Scanner;

public class Question3 {

     // Function to check if binary representation is palindromic
    public static boolean isBinaryPalindrome(int n) {
        int left = 31; // Start from MSB (for 32-bit integers)

        // Find the position of the leftmost set bit
        while (left > 0 && ((n & (1 << left)) == 0)) {
            left--;
        }

        int right = 0;

        // Compare bits from left and right towards the center
        while (left > right) {
            boolean leftBit = (n & (1 << left)) != 0;
            boolean rightBit = (n & (1 << right)) != 0;

            if (leftBit != rightBit) {
                return false;
            }

            left--;
            right++;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number: ");
        int n = sc.nextInt();
        Boolean result = isBinaryPalindrome(n);
        System.out.println(result);
        sc.close();
    }

    
}
