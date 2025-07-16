import java.util.*;
class Day31Question1 
{
    public static String check(int n) 
    {
        if (n > 0 && (n & (n - 1)) == 0)  
            return "Yes";
        else
            return "No";
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        String result = check(n);
        System.out.println("Output: " + result);
    }
}

