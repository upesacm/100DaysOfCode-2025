import java.util.*;
class Day29Question1 
{
    public static void check(int n) 
    {
        if ((n & 1) == 0) 
        {
            System.out.println("Output: Even");
        } 
        else 
        {
            System.out.println("Output: Odd");
        }
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        check(n);
    }
}
