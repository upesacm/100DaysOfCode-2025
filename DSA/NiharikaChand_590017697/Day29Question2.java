import java.util.*;
class Day29Question2
{
    public static void extract(int n, int i) 
    {
        int mask = 1 << i; 
        int result = (n & mask) != 0 ? 1 : 0; 
        System.out.println("Output: " + result);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        System.out.print("Enter bit position: ");
        int i = sc.nextInt();

        extract(n, i);
    }
}

