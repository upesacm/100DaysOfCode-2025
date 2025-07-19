import java.util.*;
public class AddOneUsingBitwise 
{
    public static void main(String[] args) 
  {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int n = sc.nextInt();
        int addOne = -~n;  
        System.out.println("Result after adding 1: " + addOne);
    }
}

