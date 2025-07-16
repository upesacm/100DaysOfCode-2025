import java.util.Scanner;
public class Day_31_Question_3 {
    // Solution 3
    public static int divideBy2(int n){
        n >>= 1;
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int num = sc.nextInt();
        num = divideBy2(num);
        System.out.print(num);
    }
}
