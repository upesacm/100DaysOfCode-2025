import java.util.*;
public class ClearRightmostSetBit 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer (n): ");
        int n = sc.nextInt();
        int result = n & (n - 1);
        System.out.println("Number after clearing rightmost set bit: " + result);
    }
}
