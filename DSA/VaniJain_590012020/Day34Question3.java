import java.util.*;
public class BinaryPalindromeCheck 
{
    public static void main(String[] args) 
  {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int n = sc.nextInt();
        if (isBinaryPalindrome(n)) 
        {
            System.out.println(n + " has a palindromic binary representation.");
        } 
        else 
        {
            System.out.println(n + " does not have a palindromic binary representation.");
        }
    }
    public static boolean isBinaryPalindrome(int n) 
  {
        int left = highestSetBitPosition(n);
        int right = 0;

        while (left > right) 
        {
            int leftBit = (n >> left) & 1;
            int rightBit = (n >> right) & 1;

            if (leftBit != rightBit) 
            {
                return false;
            }

            left--;
            right++;
        }

        return true;
    }
    public static int highestSetBitPosition(int n) 
  {
        int pos = -1;
        while (n > 0) 
        {
            n >>= 1;
            pos++;
        }
        return pos;
    }
}
