import java.util.*;

public class Day_33_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first number (a): ");
        int a = sc.nextInt();

        System.out.print("Enter second number (b): ");
        int b = sc.nextInt();

        boolean result = (a ^ b) < 0;

        System.out.println("Opposite signs: " + result);
    }
}
