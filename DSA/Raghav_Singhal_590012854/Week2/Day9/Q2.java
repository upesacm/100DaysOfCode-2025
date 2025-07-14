public class Q2 {
    public static void main(String[] args) 
    {
        String str="Programming";
        System.out.println("Vowels:"+countVnC(str)[0]+", Consonants:"+countVnC(str)[1]);
    }
    public static int[] countVnC(String str) 
    {
        int vowels=0,consonants=0;
        str=str.toLowerCase();
        for (int i = 0; i < str.length(); i++) {
            if(str.charAt(i)=='a' || str.charAt(i)=='e' || str.charAt(i)=='i' || str.charAt(i)=='o' || str.charAt(i)=='u')
                vowels++;
            else consonants++;
        }
        return new int[]{vowels,consonants};
    }
}