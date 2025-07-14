import java.util.Scanner;

public class Question3{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number
        System.out.print("Enter the number (n): ");
        int n = sc.nextInt();

        // Input bit position to set
        System.out.print("Enter the bit position to set (i): ");
        int i = sc.nextInt();

        // Set the i-th bit using OR
        int result = n | (1 << i);

        // Output the result
        System.out.println("Result after setting bit " + i + " = " + result);

        sc.close();
    }
}
