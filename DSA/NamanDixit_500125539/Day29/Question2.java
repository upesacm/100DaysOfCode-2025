import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take integer input
        
        int i = sc.nextInt();

        // Take bit position input
        int n = sc.nextInt();

        // Create bitmask by left shifting 1 by k
        int mask = 1 << n;

        // Check if the kth bit is 0 or 1
        if ((i & mask) == 0)
            System.out.println(0);
        else
            System.out.println(1);

        sc.close();
    }
}
