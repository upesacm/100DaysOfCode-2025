public class Q1 {
    public static int addOne(int n) {
        int m = 1;
        while ((n & m) != 0) {
            n = n ^ m;
            m <<= 1;
        }
        n = n ^ m;
        return n;
    }

    public static void main(String[] args) {
        System.out.println(addOne(4));
        System.out.println(addOne(7)); 
    }
}