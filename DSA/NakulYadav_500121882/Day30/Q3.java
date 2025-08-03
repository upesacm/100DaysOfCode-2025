import java.util.*;

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        countSetBits(n);
    }
    public static void countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1); 
            count++;
        }
        System.out.println(count);
    }
}
