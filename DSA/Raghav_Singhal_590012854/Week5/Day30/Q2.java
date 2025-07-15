public class Q2 {
    public static void main(String[] args) {
        int bin=10;
        int i=1;
        System.out.println(toggle(bin,i));
    }
    public static int toggle(int bin,int i)
    {
        int bitMask=1<<i;
        return(bitMask & bin) !=0 ? (bin & ~bitMask) : (bin | bitMask);
    }
}
