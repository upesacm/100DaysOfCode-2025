import java.util.*;
public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        int n = sc.nextInt();
        System.out.println("Enter the position of the bit");
        int i = sc.nextInt();
        int result = setiBit(n, i);
        System.out.println(result);
    }
    public static int setiBit(int n, int i) {
        return n | (1 << i);
    }
}
