import java.util.*;
public class DivideByTwo 
{
    public static int divideByTwo(int n) 
   {
        return n >> 1; 
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        int result = divideByTwo(n);
        System.out.println(n + " divided by 2 is: " + result);
    }
}
