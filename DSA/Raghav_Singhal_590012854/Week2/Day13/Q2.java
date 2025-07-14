public class Q2 {
    public static void main(String args[])
    {
        String str="aabbcc";
        System.out.println(canBePalin(str));
    }
    public static boolean canBePalin(String str)
    {
        str=str.toLowerCase();
        int freq[]=new int[26];
        for (char i :str.toCharArray()) {
            freq[i-'a']++;
        }
        boolean check=true;
        for (int i : freq) {
            if(i%2!=0 && check)
                check=false;
            else if(i%2!=0 && !check)
                return false;
        }
        return true;
    }
}
