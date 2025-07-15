import java.util.*;
class Day29Question3
{
    public static int setBit(int n, int i) 
    {
        int mask = 1 << i; 
        return n | mask;  
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        System.out.print("Enter bit position: ");
        int i = sc.nextInt();

        int newNum = setBit(n, i);
        System.out.println("Output: " + newNum);
    }
}

