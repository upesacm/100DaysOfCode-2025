public class Q3 {
    public static int isoRight(int n)
    {
        return n & -n;
    }

    public static void main(String[] args) {
        System.out.println(isoRight(10)); 
        System.out.println(isoRight(12)); 
    }
}
