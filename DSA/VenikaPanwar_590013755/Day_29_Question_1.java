import java.util.*;

public class Day_29_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter an integer: ");
        int n = sc.nextInt();

        // Least significant bit tells the parity
        if ((n & 1) == 0)
            System.out.println("Even");
        else
            System.out.println("Odd");
    }
}
