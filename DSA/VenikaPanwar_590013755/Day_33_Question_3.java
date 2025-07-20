import java.util.*;

public class Day_33_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number: ");
        int n = sc.nextInt();

        int result = n & -n;

        System.out.println("Rightmost set bit isolated: " + result);
    }
}
