import java.util.*;

public class LongestKUniqueSubstring {
    public static int longestKUnique(String str, int k) {
        int left = 0, maxLen = 0;
        Map<Character, Integer> map = new HashMap<>();

        for (int right = 0; right < str.length(); right++) {
            char c = str.charAt(right);
            map.put(c, map.getOrDefault(c, 0) + 1);

            while (map.size() > k) {
                char leftChar = str.charAt(left);
                map.put(leftChar, map.get(leftChar) - 1);
                if (map.get(leftChar) == 0) map.remove(leftChar);
                left++;
            }

            if (map.size() == k) {
                maxLen = Math.max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        String str1 = "aabacbebebe";
        int k1 = 3;
        System.out.println("Output 1: " + longestKUnique(str1, k1)); // 7

        String str2 = "aaaa";
        int k2 = 2;
        System.out.println("Output 2: " + longestKUnique(str2, k2)); // 0
    }
}
