public class question1 {
    public static void main(String[] args) {
        int a = 5;
        int b = 9;

        System.out.println("Before swap: a = " + a + ", b = " + b);

        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        System.out.println("After swap: a = " + a + ", b = " + b);
    }
}
