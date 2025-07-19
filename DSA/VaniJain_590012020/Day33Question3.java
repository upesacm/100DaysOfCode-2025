import java.util.Scanner;
public class IsolateRightmostSetBit 
{
    public static void main(String[] args) 
{
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer (n): ");
        int n = sc.nextInt();
        int result = n & -n;
        System.out.println("Isolated rightmost set bit: " + result);
    }
}
