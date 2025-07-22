import java.util.*;
public class MultiplyByTwo {
    public static int multiplyByTwo(int n) 
  {
        return n << 1; 
  }
    public static void main(String[] args) 
  {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        int result = multiplyByTwo(n);
        System.out.println(n + " multiplied by 2 is: " + result);
  }
}
