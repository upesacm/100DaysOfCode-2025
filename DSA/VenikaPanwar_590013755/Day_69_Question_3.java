import java.util.*;

public class Day_69_Question_3 {
    /**
     * Returns length of longest substring without repeating characters.
     * Uses sliding window and HashSet for uniqueness.
     */
    public static int longestUniqueSubstring(String s) {
        Set<Character> seen = new HashSet<>();
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.length(); right++) {
            while (seen.contains(s.charAt(right))) {
                seen.remove(s.charAt(left));
                left++;
            }
            seen.add(s.charAt(right));
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter string: ");
        String input = scanner.nextLine();
        int result = longestUniqueSubstring(input);
        System.out.println(result);

        // Example demonstrations
        System.out.println("Example: \"abcabcbb\" -> " + longestUniqueSubstring("abcabcbb"));
        System.out.println("Example: \"bbbbb\" -> " + longestUniqueSubstring("bbbbb"));
    }
}
