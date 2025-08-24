import java.util.*;

public class Day_69_Question_1 {
    /**
     * Checks if the characters of a string can be rearranged to form a palindrome.
     * Uses frequency analysis: at most one character can have odd count.
     */
    public static boolean canFormPalindrome(String str) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char c : str.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        int oddCount = 0;
        for (int count : freq.values()) {
            if (count % 2 != 0) oddCount++;
        }
        return oddCount <= 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter string: ");
        String input = scanner.nextLine();
        boolean result = canFormPalindrome(input);
        System.out.println(result ? "Yes" : "No");

        // Example demonstrations
        System.out.println("Example: \"civic\" -> " + (canFormPalindrome("civic") ? "Yes" : "No"));
        System.out.println("Example: \"aabbcc\" -> " + (canFormPalindrome("aabbcc") ? "Yes" : "No"));
        System.out.println("Example: \"abc\" -> " + (canFormPalindrome("abc") ? "Yes" : "No"));
        scanner.close();
    }
}
