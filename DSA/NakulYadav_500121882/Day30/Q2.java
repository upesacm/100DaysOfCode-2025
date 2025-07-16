import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i = sc.nextInt(); 
        toggleIthBit(n, i);
    }
    public static void toggleIthBit(int n, int i) {
        int result = n ^ (1 << i);
        System.out.println(result);
    }
}
