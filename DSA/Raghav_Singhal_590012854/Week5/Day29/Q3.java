public class Q3 {
    public static void main(String[] args) {
        int bin=8;
        int i=2;
        System.out.println(odEv(bin,i));
    }
    public static int odEv(int bin,int i)
    {
        int bitMask=1<<i;
        return (bin | bitMask);
    }
}
