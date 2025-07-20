public class Q3 
{
    public static String plain(int n) 
    {
        int rev = 0; 
        int temp = n;
        while (temp > 0) 
        {
            rev = (rev << 1) | (temp & 1);
            temp >>= 1;
        }
        return n == rev ? "Yes":"No";
    }
    public static void main(String[] args) 
    {
        System.out.println(plain(9));
        System.out.println(plain(10));
    }
}
