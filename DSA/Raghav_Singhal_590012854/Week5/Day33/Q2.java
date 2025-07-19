public class Q2 {
    public static int turnRight(int n) {
        return n & (n - 1);
    }

    public static void main(String[] args) {
        System.out.println(turnRight(12));
        System.out.println(turnRight(10)); 
    }
}
