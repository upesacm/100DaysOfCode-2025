public class Q1 {
    public static void main(String[] args) {
        String str="Hello world programming";
        System.out.println(wCountandLongest(str));
    }
    public static String wCountandLongest(String str)
    {
        String longestWord="";
        str=str.trim();
        String arr[]=str.split("\\s+");
        for (String i : arr) {
            if(i.length() > longestWord.length())
                longestWord = i;
        }
        return "Word count: "+arr.length+", Longest word: \""+longestWord+"\"";
    }
}