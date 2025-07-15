import java.util.*;
public class CheckBitSet 
{
    public static void main(String[] args) 
  {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer (n): ");
        int n = sc.nextInt();
        System.out.print("Enter the bit position (i): ");
        int i = sc.nextInt();
        if ((n & (1 << i)) != 0)
            System.out.println("The " + i + "-th bit is SET (1).");
        else
            System.out.println("The " + i + "-th bit is NOT SET (0).");
    }
}
