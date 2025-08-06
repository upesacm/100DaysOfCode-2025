import java.util.*;

public class MinimumWindowSubstring {
    public static String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";

        Map<Character, Integer> tMap = new HashMap<>();
        for (char ch : t.toCharArray())
            tMap.put(ch, tMap.getOrDefault(ch, 0) + 1);

        Map<Character, Integer> window = new HashMap<>();
        int left = 0, start = 0, minLen = Integer.MAX_VALUE, matched = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            window.put(ch, window.getOrDefault(ch, 0) + 1);

            if (tMap.containsKey(ch) && window.get(ch).intValue() <= tMap.get(ch).intValue())
                matched++;

            while (matched == t.length()) {
                if ((right - left + 1) < minLen) {
                    start = left;
                    minLen = right - left + 1;
                }

                char leftChar = s.charAt(left);
                window.put(leftChar, window.get(leftChar) - 1);
                if (tMap.containsKey(leftChar) && window.get(leftChar) < tMap.get(leftChar))
                    matched--;

                left++;
            }
        }

        return (minLen == Integer.MAX_VALUE) ? "" : s.substring(start, start + minLen);
    }

    public static void main(String[] args) {
        System.out.println("Output 1: " + minWindow("ADOBECODEBANC", "ABC")); // BANC
        System.out.println("Output 2: " + minWindow("a", "a"));                // a
    }
}
