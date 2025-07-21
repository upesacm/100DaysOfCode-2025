import java.util.*;
class Day33Question3
{
    public static int isolateRightmost(int n) 
    {
        return n & -n;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int result = isolateRightmost(n);
        System.out.println("Output: " + result);
    }
}

