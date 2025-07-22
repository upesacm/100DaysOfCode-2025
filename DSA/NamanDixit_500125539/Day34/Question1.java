import java.util.Scanner;

public class Question1 {


    // Function to add 1 using only bitwise operations
    public static int addOne(int n) {
        int m = 1; // Initialize carry as 1 (i.e., we want to add 1)

        // Iterate till there is no carry
        while ((n & m) != 0) {
            n = n ^ m; // Flip the bit
            m = m << 1; // Move to next bit (carry forward)
        }

        // Set the final carry bit
        n = n ^ m;

        return n;
    }
public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number: ");
        int n = sc.nextInt();
        int result = addOne(n);
        System.out.println(result);
        sc.close();
    }
    
}
