import java.util.*;

public class Q1 {
    public static boolean canFormPalindrome(String s) {
        int[] freq = new int[256];
        for (char c : s.toCharArray()) freq[c]++;
        int oddCount = 0;
        for (int f : freq) {
            if (f % 2 != 0) oddCount++;
            if (oddCount > 1) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(canFormPalindrome(s));
        sc.close();
    }
}
