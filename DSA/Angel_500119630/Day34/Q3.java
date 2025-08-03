public class Q3{
    public static void main(String[] args) {
        int n = 9;
        System.out.println("Is Palindrome: " + isBinaryPalindrome(n));
    }

    public static String isBinaryPalindrome(int n) {
        int left = 31, right = 0;
        while (((n >> left) & 1) == 0 && left > right) left--;
        while (left > right) {
            int leftBit = (n >> left) & 1;
            int rightBit = (n >> right) & 1;
            if (leftBit != rightBit) return "No";
            left--;
            right++;
        }
        return "Yes";
    }
}
