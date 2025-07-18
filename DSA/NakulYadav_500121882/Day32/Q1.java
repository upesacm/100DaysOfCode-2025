public class Q1{
    public static void main(String[] args) {
        int a = 4, b = 7;
        System.out.println("Before Swap: a = " + a + ", b = " + b);
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        System.out.println("After Swap:  a = " + a + ", b = " + b);
    }
}
