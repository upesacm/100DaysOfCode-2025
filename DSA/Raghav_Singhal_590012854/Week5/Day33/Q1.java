public class Q1 {
    public static boolean OppSigns(int a, int b) 
    {
        return (a ^ b) < 0;
    }

    public static void main(String[] args) {
        System.out.println(OppSigns(2, -3));
        System.out.println(OppSigns(-4, -5));
    }
}
