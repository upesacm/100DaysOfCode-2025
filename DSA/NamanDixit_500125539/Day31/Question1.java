
import java.util.*;

public class Question1 {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int val = (n & (n - 1));
        if (val == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
