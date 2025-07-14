public class Q1 {
    public static void main(String[] args) {
        String str = "A man, a plan, a canal: Panama";
        System.out.println(isPlinwithoutSnP(str));
    }

    public static boolean isPlinwithoutSnP(String str) {
        str = str.replaceAll("\\W", "").toLowerCase();
        int half = str.length() % 2 == 0 ? str.length() / 2 : str.length() / 2 + 1;
        for (int i = 0; i < half; i++) {
            if (str.charAt(i) != str.charAt(str.length() - i - 1))
                return false;
        }
        return true;
    }
}