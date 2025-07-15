public class Q2 {
    public static void main(String[] args) {
        String str="babad";
        System.out.println(longPalin(str));
    }
    public static String longPalin(String str)
    {
        String max = String.valueOf(str.charAt(0)), cur="";
        for (int i = 0; i < str.length(); i++) {
            for (int j = i; j < str.length(); j++) {
                if(isPalin(str.substring(i, j+1)))
                {
                    cur=str.substring(i, j+1);
                    if(cur.length()>max.length())
                        max=cur;
                }
            }
        }
        return max;
    }
    public static boolean isPalin(String str)
    {
        for (int i = 0; i < str.length() / 2; i++) {
            if(str.charAt(i)!=str.charAt(str.length()-1-i))
                return false;
        }
        return true;
    }
}
