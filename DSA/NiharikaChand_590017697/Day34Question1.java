import java.util.*;
class Day34Question1
{
    public static int add(int n) 
    {
        int mask = 1;

        while ((n & mask) != 0) 
        {
            n = n ^ mask;
            mask <<= 1;     
        }

        n = n ^ mask; 
        return n;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        int result = add(n);
        System.out.println("Output: " + result);
    }
}
