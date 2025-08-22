import java.util.*;

public class Q3 {
    public static void main(String[] args) {
        String s = "ADOBECODEBANC";
        String t = "ABC";
        System.out.println(minWindow(s, t));
    }

    public static String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";

        Map<Character, Integer> tFreq = new HashMap<>();
        for (char c : t.toCharArray()) tFreq.put(c, tFreq.getOrDefault(c, 0) + 1);

        Map<Character, Integer> window = new HashMap<>();
        int left = 0, right = 0, required = tFreq.size(), formed = 0;
        int[] ans = {-1, 0, 0}; 
        while (right < s.length()) {
            char c = s.charAt(right);
            window.put(c, window.getOrDefault(c, 0) + 1);

            if (tFreq.containsKey(c) && window.get(c).intValue() == tFreq.get(c).intValue())
                formed++;

            while (left <= right && formed == required) {
                if (ans[0] == -1 || right - left + 1 < ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }

                char leftChar = s.charAt(left);
                window.put(leftChar, window.get(leftChar) - 1);
                if (tFreq.containsKey(leftChar) && window.get(leftChar).intValue() < tFreq.get(leftChar))
                    formed--;
                left++;
            }
            right++;
        }

        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }
}
