import java.util.Scanner;

public class DivideByTwo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int result = n >> 1;  // right shift by 1 = divide by 2 (integer part only)

        System.out.println("Result: " + result);
    }
}
