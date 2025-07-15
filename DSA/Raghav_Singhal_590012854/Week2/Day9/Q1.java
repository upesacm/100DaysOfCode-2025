public class Q1 {
    public static void main(String args[])
    {
        String str="racecar";
        System.out.println(isPalin(str));
    }
    public static boolean isPalin(String str)
    {
        int half;
        if(str.length()%2==0)
        half=str.length()/2;
        else
        half=str.length()/2+1;
        for (int i = 0; i <= half; i++) {
            if(str.charAt(i)!=str.charAt(str.length()-1-i))
            return false;
        }
        return true;
    }
}