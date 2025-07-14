import java.util.Scanner;
public class Day_29_Question_1{
    // Solution 1
    public static void checkEvenOrOdd(int n){
        if((n & 1) == 0) System.out.print("Number is even");
        else System.out.print("Number is odd");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int num = sc.nextInt();
        checkEvenOrOdd(num);
    }
}
