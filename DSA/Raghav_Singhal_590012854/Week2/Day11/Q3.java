public class Q3 {
    public static void main(String[] args) {
        String str="aaa";
        System.out.println(totalPalin(str));
    }
    public static int totalPalin(String str)
    {
        int count=0;
        for (int i = 0; i < str.length(); i++) {
            for (int j = i; j < str.length(); j++) {
                if(isPalin(str.substring(i, j+1)))
                {
                    count++;
                }
            }
        }
        return count;
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
