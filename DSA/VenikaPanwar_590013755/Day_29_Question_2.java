import java.util.*;

public class Day_29_Question_2
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number (n): ");
        int n = sc.nextInt();

        System.out.print("Enter bit position (i): ");
        int i = sc.nextInt();

        int mask = 1 << i;
        int bit = (n & mask) != 0 ? 1 : 0;

        System.out.println("The " + i + "-th bit is: " + bit);
    }
}
