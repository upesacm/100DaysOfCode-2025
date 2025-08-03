import java.util.*;

public class Day_34_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int left = 31; // MSB
        int right = 0; // LSB

        while (left > right) {
            // Skip leading 0s on left
            if (((n >> left) & 1) == 0) {
                left--;
                continue;
            }

            // Skip trailing 0s on right
            if (((n >> right) & 1) == 0) {
                right++;
                continue;
            }

            if (((n >> left) & 1) != ((n >> right) & 1)) {
                System.out.println("No");
                return;
            }

            left--;
            right++;
        }

        System.out.println("Yes");
    }
}
