public class Q1 {
    public static boolean haveOppositeSigns(int a, int b) {
        return (a ^ b) < 0;
    }

    public static void main(String[] args) {
        System.out.println(haveOppositeSigns(2, -3));  
    }
}
