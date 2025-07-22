import java.util.*;
class Day32Question1
{
    public static void swap(int a, int b) 
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        System.out.println("Output: a = " + a + ", b = " + b);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int a = sc.nextInt();
        System.out.print("Enter second number: ");
        int b = sc.nextInt();

        swap(a, b);
    }
}
