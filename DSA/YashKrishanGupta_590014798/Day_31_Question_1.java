import java.util.Scanner;
public class Day_31_Question_1{
    // Solution 1
    public static void isPowerOf2(int n){
        if((n&(n-1))==0) System.out.println("Number is in power of 2");
        else System.out.println("Number is not in power of 2");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int num = sc.nextInt();
        isPowerOf2(num);
    }
}
