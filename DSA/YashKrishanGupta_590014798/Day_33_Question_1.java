import java.util.Scanner;
public class Day_33_Question_1 {

    // Solution 1
    public static boolean oppositeSignCheck(int a ,int b) {
        return (a ^ b) < 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two integers : ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(oppositeSignCheck(a,b));

    }
