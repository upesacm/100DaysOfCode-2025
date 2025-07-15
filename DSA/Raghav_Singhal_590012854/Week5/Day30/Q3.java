public class Q3 {
    public static void main(String[] args) {
        int bin=7;
        System.out.println(toggle(bin));
    }
    public static int toggle(int bin)
    {
        int count=0;
        while(bin>0)
        {
            if((bin&1)==1)
                count++;
            bin=bin>>1;
        }
        return count;
    }
}
