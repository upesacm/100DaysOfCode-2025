import java.util.*;
class Day30Question1
{
    public static int clear(int n, int i) 
    {
        int mask = ~(1 << i);  
        return n & mask;     
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        System.out.print("Enter bit position to clear: ");
        int i = sc.nextInt();

        int result = clear(n, i);
        System.out.println("Output: " + result);
    }
}
