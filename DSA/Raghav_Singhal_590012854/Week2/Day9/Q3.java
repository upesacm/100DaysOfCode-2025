public class Q3 {
    public static void main(String args[])
    {
        String str="programming";
        System.out.println("'"+firstNonRep(str)+"'");
    }
    public static Character firstNonRep(String str)
    {
        char ch;
        int count;
        for (int i = 0; i < str.length(); i++) 
        {
            count = 0;
            ch = str.charAt(i);
            for (int j = 0; j < str.length(); j++) 
            {
                if (str.charAt(j) == ch)
                    count++;
            }
            if (count == 1) return ch;
        }
        return null;
    }
}