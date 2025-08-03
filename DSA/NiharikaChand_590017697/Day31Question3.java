import java.util.*;
class Day31Question3
{
    public static int divide(int n) 
    {
        return n >> 1;  
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int result = divide(n);
        System.out.println("Output: " + result);
    }
}
