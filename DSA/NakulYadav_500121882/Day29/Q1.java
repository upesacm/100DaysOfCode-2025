import java.util.*;
public class Q1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a Number: ");
        int a = sc.nextInt();
        checkEvenOdd(a);
    }
    public static void checkEvenOdd(int a){
        if((a & 1) == 0) {
            System.out.println("The number is Even");
        } else {
            System.out.println("The number is Odd");
        }
    }
}
