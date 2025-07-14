import java.util.*;

public class Day_29_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number (n): ");
        int n = sc.nextInt();

        System.out.print("Enter the bit position to set (i): ");
        int i = sc.nextInt();

        int mask = 1 << i;
        int result = n | mask;

        System.out.println("New number after setting bit " + i + ": " + result);
    }
}
