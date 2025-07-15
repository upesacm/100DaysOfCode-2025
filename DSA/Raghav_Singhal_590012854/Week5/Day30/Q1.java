public class Q1 {
    public static void main(String[] args) {
        int bin=7;
        int i=1;
        System.out.println(clear(bin,i));
    }
    public static int clear(int bin,int i)
    {
        int bitMask=1<<i;
        return (bin & ~bitMask);
    }
}
