import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Question2 {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int right = 0;
        Set<Character> seen = new HashSet<>();
        int max = 0;

        while (right < s.length()) {
            char c = s.charAt(right);
            // If character is not in the set, add it and expand the window
            if (!seen.contains(c)) {
                seen.add(c);
                max = Math.max(max, right - left + 1);
                right++; // Expand the window by moving right pointer
            } else {
                // If character is a duplicate, shrink the window by moving left
                while (s.charAt(left) != c) {
                    seen.remove(s.charAt(left)); // Remove characters until the duplicate is gone
                    left++;
                }
                // Remove the duplicate character and move left pointer by one
                seen.remove(s.charAt(left));
                left++;
            }
        }
        return max; // Return the maximum length of the substring without repeating characters
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String input = sc.nextLine();

        Question2 obj = new Question2();
        int result = obj.lengthOfLongestSubstring(input);
        System.out.println(result);

        sc.close();
    }
}
