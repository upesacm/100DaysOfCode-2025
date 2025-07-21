public class Q1{
    public static void main(String[] args) {
        int n = 4;
        System.out.println("Result: " + addOne(n));
    }

    public static int addOne(int n) {
        int mask = 1;
        while ((n & mask) != 0) {
            n = n ^ mask;
            mask = mask << 1;
        }
        n = n ^ mask;
        return n;
    }
}
