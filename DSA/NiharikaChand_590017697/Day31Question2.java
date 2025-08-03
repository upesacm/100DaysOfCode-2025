import java.util.*;
class Day31Question2 
{
    public static int multiply(int n) 
    {
        return n << 1; 
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int result = multiply(n);
        System.out.println("Output: " + result);
    }
}
