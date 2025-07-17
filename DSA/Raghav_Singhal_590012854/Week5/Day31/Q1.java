public class Q1 {
    public static void main(String[] args) {
        int bin=8;
        System.out.println(check(bin));
    }
    public static String check(int bin)
    {
        return bin>0 && (bin & (bin-1))==0?"Yes":"No";
    }
}