import java.util.Scanner;
public class Day_31_Question_2{
    // Solution 2
    public static int multiplyBy2(int n){
        n <<= 1;
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int num = sc.nextInt();
        num = multiplyBy2(num);
        System.out.print(num);
    }
}
