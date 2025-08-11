import java.util.*;

public class Q3 {
    public static void main(String args[]) {
        String s = "ADOBECODEBANC", t = "ABC";
        System.out.println(shortA(s, t));
    }

    static String shortA(String s, String t) {
        Set<Character> Sett = new HashSet<>();
        for (char i : t.toCharArray())
            Sett.add(i);
        int c;
        String fin = "", ch;
        for (int i = 0; i < s.length(); i++) {
            c = 0;
            ch = "";
            for (int j = i; j < s.length(); j++) {
                if(Sett.contains(s.charAt(j)))
                    c++;
                else if(ch.equals(""))
                {
                    break;
                }
                ch+=s.charAt(j);
                if(c==t.length())
                {
                    if(fin.length()==0 || fin.length()>ch.length())
                    {
                        fin=ch;
                    }
                    break;
                }
            }
        }
        return fin;
    }
}
