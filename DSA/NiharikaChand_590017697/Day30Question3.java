import java.util.*;
class Day30Question3
{
    public static int count(int n) 
    {
        int c = 0;
        while (n > 0) 
        {
            n = n & (n - 1);  
            c++;
        }
        return c;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int result = count(n);
        System.out.println("Output: " + result);
    }
}
