import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        String text = "forxxorfxdofr";
        String pattern = "for";
        System.out.println(countAnagrams(text, pattern));
    }

    public static int countAnagrams(String txt, String pat) {
        int[] freq = new int[26];
        for (char ch : pat.toCharArray()) freq[ch - 'a']++;

        int count = 0, start = 0, matches = pat.length();
        int[] window = new int[26];

        for (int end = 0; end < txt.length(); end++) {
            char endChar = txt.charAt(end);
            window[endChar - 'a']++;

            if (end - start + 1 == pat.length()) {
                if (Arrays.equals(freq, window)) count++;

                char startChar = txt.charAt(start);
                window[startChar - 'a']--;
                start++;
            }
        }
        return count;
    }
}
