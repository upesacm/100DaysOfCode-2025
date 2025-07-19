import java.util.Scanner;

public class Question3 {
    
    // Function to isolate rightmost set bit of integer n
    public static int isolateRightMostSetBit(int n) {
        int result = n & (-n);
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number: ");
        int n = sc.nextInt();
        int result = isolateRightMostSetBit(n);
        System.out.println(result);
        sc.close();
    }
}
