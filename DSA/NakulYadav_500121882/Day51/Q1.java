import java.util.*;
public class Q1 {
    public static void main(String[] args) {
        String str = "aabacbebebe";
        int k = 3;
        System.out.println(longestSubstringWithKUnique(str, k));
    }

    public static int longestSubstringWithKUnique(String s, int k) {
        if (s == null || s.length() == 0 || k == 0) return 0;

        int maxLen = 0;
        Map<Character, Integer> freqMap = new HashMap<>();
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            freqMap.put(s.charAt(right), freqMap.getOrDefault(s.charAt(right), 0) + 1);

            while (freqMap.size() > k) {
                char leftChar = s.charAt(left);
                freqMap.put(leftChar, freqMap.get(leftChar) - 1);
                if (freqMap.get(leftChar) == 0) freqMap.remove(leftChar);
                left++;
            }

            if (freqMap.size() == k)
                maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }
}
