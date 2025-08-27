import java.util.*;

public class Question3 {

    // Function to find length of the longest substring without repeating characters
    public static int lengthOfLongestSubstring(String s) {
        Set<Character> charSet = new HashSet<>();

        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            while (charSet.contains(s.charAt(right))) {
                charSet.remove(s.charAt(left));
                left++;
            }
            charSet.add(s.charAt(right));
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take input from user
        System.out.print("Enter a string: ");
        String s = sc.nextLine();

        // Print result
        System.out.println(lengthOfLongestSubstring(s));
    }
}
