import java.util.Scanner;

public class Question1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take input from user
        System.out.print("Enter first number (x): ");
        int x = sc.nextInt();

        System.out.print("Enter second number (y): ");
        int y = sc.nextInt();

        // Check if x and y have opposite signs using bitwise XOR
        boolean hasOppositeSigns = ((x ^ y) < 0);

        if (hasOppositeSigns)
            System.out.println("True");
        else
            System.out.println("False");

        sc.close();
    }
}
