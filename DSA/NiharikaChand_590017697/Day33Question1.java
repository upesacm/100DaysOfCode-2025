import java.util.*;
class Day33Question1
{
    public static boolean checkSigns(int a, int b) 
    {
        return ((a ^ b) < 0);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int a = sc.nextInt();
        System.out.print("Enter second number: ");
        int b = sc.nextInt();

        boolean result = checkSigns(a, b);
        System.out.println("Output: " + result);
    }
}


