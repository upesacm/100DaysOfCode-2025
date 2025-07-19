import java.util.Scanner;

public class Question2 {
    
    // Function to clear rightmost set bit of integer n
    public static int clearRightMostSetBit(int n) {
        int result = n & (n - 1);
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Number: ");
        int n = sc.nextInt();
        int result = clearRightMostSetBit(n);
        System.out.println(result);
    }
}
