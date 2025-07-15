import java.util.Arrays;

public class Q3 {
    public static void main(String[] args) {
        String String1="listen", String2="silent";
        System.out.println(areAnagrams(String1, String2));
    }    
     public static boolean areAnagrams(String str1, String str2) {
        String s1 = str1.replaceAll("\\s+", "").toLowerCase();
        String s2 = str2.replaceAll("\\s+", "").toLowerCase();
        if (s1.length() != s2.length())
            return false;
        char[] arr1 = s1.toCharArray();
        char[] arr2 = s2.toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        return Arrays.equals(arr1, arr2);
    }
}