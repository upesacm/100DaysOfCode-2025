import java.util.Scanner;
public class OppositeSignsCheck 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first integer (a): ");
        int a = sc.nextInt();
        System.out.print("Enter second integer (b): ");
        int b = sc.nextInt();
        if ((a ^ b) < 0) 
        {
            System.out.println("a and b have opposite signs.");
        } 
        else 
        {
            System.out.println("a and b have the same sign.");
        }
    }
}
