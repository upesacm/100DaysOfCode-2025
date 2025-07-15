public class Q1 {
    public static void main(String[] args) {
        int bin= 4;
        System.out.println(odEv(bin));
    }
    public static String odEv(int bin)
    {
        return (bin & 1) == 1?"Odd":"Even";
    }
}
