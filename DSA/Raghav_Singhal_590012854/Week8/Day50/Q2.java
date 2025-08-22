public class Q2 {
    public static void main(String args[]) {
        String text = "aabaabaa", pattern = "aaba";
        System.out.println(klen(text, pattern));
    }

    static int klen(String str, String p) {
        int count = 0;
        for (int i = 0; i <= str.length() - p.length(); i++) {
            int[] ch = charCount(p);
            for (int j = i; j < i+p.length(); j++) {
                if (!isMt(ch) && ch[str.charAt(j) - 'a'] > 0) {
                    ch[str.charAt(j) - 'a']--;
                }
            }
            if (isMt(ch))
                count++;
        }
        return count;
    }

    public static int[] charCount(String p) {
        int arr[] = new int[26];
        for (int i = 0; i < 26; i++) {
            arr[i] = 0;
        }
        for (int i = 0; i < p.length(); i++) {
            arr[p.charAt(i) - 'a']++;
        }
        return arr;
    }

    static boolean isMt(int arr[]) {
        for (int i : arr) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
}
