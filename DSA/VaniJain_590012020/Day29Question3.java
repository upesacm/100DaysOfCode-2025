import java.util.*;
public class SetBitAtPosition 
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer (n): ");
        int n = sc.nextInt();
        System.out.print("Enter the bit position to set (i): ");
        int i = sc.nextInt();
        int result = n | (1 << i);
        System.out.println("Number after setting " + i + "-th bit: " + result);
    }
}
