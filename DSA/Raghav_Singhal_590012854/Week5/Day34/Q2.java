public class Q2 {

    public static int subtract(int a) {
        int b=1;
        while (b != 0) {
            int borrow = (~a) & b;
            a = a ^ b;
            b = borrow << 1;
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println(subtract(5));
        System.out.println(subtract(8));
    }
}
