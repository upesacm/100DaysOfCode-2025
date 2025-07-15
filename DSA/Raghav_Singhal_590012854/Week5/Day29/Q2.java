public class Q2 {
    public static void main(String[] args) {
        int bin=5;
        int i=0;
        System.out.println(odEv(bin,i));
    }
    public static int odEv(int bin,int i)
    {
        int bitMask=1<<i;
        return (bin & bitMask) == 1?1:0;
    }
}
