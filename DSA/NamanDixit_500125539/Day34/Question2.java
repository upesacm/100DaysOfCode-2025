import java.util.Scanner;

public class Question2 {
    public static int subtractOne(int n) {
    int m = 1; // Initial borrow bit

    // Continue while there is a borrow
    while ((n & m) == 0) {
        n = n ^ m; // Flip 0 to 1 (borrow from higher bit)
        m = m << 1; // Move borrow to next bit
    }

    // Flip the first 1 to 0 to complete subtraction
    n = n ^ m;

    return n;
}

public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number: ");
        int n = sc.nextInt();
        int result = subtractOne(n);
        System.out.println(result);
        sc.close();
    }

    
}
