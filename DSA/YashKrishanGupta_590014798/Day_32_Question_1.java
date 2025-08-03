import java.util.Scanner;
public class Day_32_Question_1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a : ");
        int a = sc.nextInt();
        System.out.print("Enter b : ");
        int b = sc.nextInt();
        System.out.println("Before swap :- a = "+a+" , b = "+b);
        // Swapping a and b (Solution - 1)
        a = a^b;
        b = a^b;
        a = a^b;
        System.out.println("After swap :- a = "+a+" , b = "+b);
    }
}
