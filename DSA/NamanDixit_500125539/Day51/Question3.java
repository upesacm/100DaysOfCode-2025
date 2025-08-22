import java.util.*;

public class Question3 {

    public static String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";

        Map<Character, Integer> tFreq = new HashMap<>();
        for (char ch : t.toCharArray()) {
            tFreq.put(ch, tFreq.getOrDefault(ch, 0) + 1);
        }

        Map<Character, Integer> windowFreq = new HashMap<>();
        int have = 0, need = tFreq.size();
        int left = 0, minLen = Integer.MAX_VALUE;
        int resLeft = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            windowFreq.put(ch, windowFreq.getOrDefault(ch, 0) + 1);

            if (tFreq.containsKey(ch) && windowFreq.get(ch).intValue() == tFreq.get(ch).intValue()) {
                have++;
            }

            // Shrink window
            while (have == need) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    resLeft = left;
                }

                char leftChar = s.charAt(left);
                windowFreq.put(leftChar, windowFreq.get(leftChar) - 1);
                if (tFreq.containsKey(leftChar) && windowFreq.get(leftChar) < tFreq.get(leftChar)) {
                    have--;
                }
                left++;
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(resLeft, resLeft + minLen);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the main string: ");
        String s = sc.nextLine();

        System.out.print("Enter the target string: ");
        String t = sc.nextLine();

        String result = minWindow(s, t);
        System.out.println(result);

    }
}
