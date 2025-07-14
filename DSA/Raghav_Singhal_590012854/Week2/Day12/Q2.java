public class Q2 {
    public static void main(String[] args) {
        String str="programming";
        System.out.println(noDups(str));
    }
    public static String noDups(String str)
    {
        String newStr="";
        for (int i = 0; i < str.length(); i++) {
            if(!(newStr.contains(String.valueOf(str.charAt(i)))))
                newStr+=str.charAt(i);
        }
        return "\""+newStr+"\"";
    }
}