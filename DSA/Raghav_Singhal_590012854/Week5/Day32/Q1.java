public class Q1 {
    public static void main(String[] args) {
        int a=8,b=10;
        System.out.println("Before \n a= " + a + ", b = " + b);
        System.out.println("After \n a= " + swapped(a,b)[0] + ", b = " + swapped(a,b)[1]);
    }
    public static int[] swapped(int a,int b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        return new int []{a,b};
    }
}