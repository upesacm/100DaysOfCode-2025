import java.util.*;

public class Q1 {
    public static void main(String args[]) {
        String str = "aabacbebebe";
        int k = 3;
        System.out.println(longS(str, k));
    }

    static int longS(String str, int k) {
        Set<Character> sett = new HashSet<>();
        int val = 0, fin = 0;
        for (int i = 0; i < (str.length()); i++) {
            char ch = str.charAt(i);
            if (sett.size() == 4) {
                sett.clear();
                fin = val;
            }
            sett.add(ch);
            val++;

        }
        return fin;
    }
}
