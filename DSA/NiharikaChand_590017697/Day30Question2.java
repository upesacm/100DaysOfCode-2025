import java.util.*;
class Day30Question2 
{
    public static int toggle(int n, int i) 
    {
        int mask = (1 << i);  
        return n ^ mask;      
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        System.out.print("Enter bit position to toggle: ");
        int i = sc.nextInt();

        int result = toggle(n, i);
        System.out.println("Output: " + result);
    }
}
