import java.util.*;

public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); 
        int i = sc.nextInt(); 
        clearIthBit(n, i);
    }
    public static void clearIthBit(int n, int i) {
        int result = n & ~(1 << i);
        System.out.println(result);
    }
}
