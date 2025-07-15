import java.util.*;
public class ToggleBitAtPosition
  {
    public static void main(String[] args) 
  {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number (n): ");
        int n = sc.nextInt();
        System.out.print("Enter the bit position to toggle (i): ");
        int i = sc.nextInt();
        int mask = (1 << i);  
        int result = n ^ mask; 
        System.out.println("Number after toggling " + i + "-th bit: " + result);
    }
}
