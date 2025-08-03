import java.util.Scanner;
public class Day_34_Question_2 {
    // Solution 2
    public static int decrement(int n){
        int borrow = 1;
        while(borrow!=0){
            int diff = n ^ borrow;
            borrow = (~n & borrow)<<1;
            n = diff;
        }
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Integer : ");
        int num = sc.nextInt();
        num = decrement(num);
        System.out.print(num);
    }
}
