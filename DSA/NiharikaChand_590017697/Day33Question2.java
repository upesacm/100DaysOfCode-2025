import java.util.*;
class Day33Question2
{
    public static int turnOff(int n) 
    {
        return n & (n - 1);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int result = turnOff(n);
        System.out.println("Output: " + result);
    }
}
