public class Q2{
    public static void main(String[] args) {
        int n = 5;
        System.out.println("Result: " + subtractOne(n));
    }

    public static int subtractOne(int n) {
        int mask = 1;
        while ((n & mask) == 0) {
            n = n ^ mask;
            mask = mask << 1;
        }
        n = n ^ mask;
        return n;
    }
}
