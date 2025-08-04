import java.util.*;

public class CountAnagramOccurrences {
    public static int countAnagrams(String text, String pattern) {
        int[] patCount = new int[26];
        int[] winCount = new int[26];
        int count = 0;
        int k = pattern.length();

        for (char c : pattern.toCharArray())
            patCount[c - 'a']++;

        for (int i = 0; i < text.length(); i++) {
            winCount[text.charAt(i) - 'a']++;

            if (i >= k) {
                winCount[text.charAt(i - k) - 'a']--; // remove oldest char
            }

            if (Arrays.equals(patCount, winCount)) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        String text = "forxxorfxdofr";
        String pattern = "for";
        System.out.println("Anagram occurrences: " + countAnagrams(text, pattern));
    }
}
