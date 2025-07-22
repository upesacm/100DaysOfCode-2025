import java.util.Scanner;
public class Day_34_Question_1 {
    // Solution 1
    public static int increment(int n){
        int carry = 1;
        while(carry!=0){
            int sum = n ^ carry;
            carry = (n & carry)<<1;
            n = sum;
        }
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Integer : ");
        int num = sc.nextInt();
        num = increment(num);
        System.out.print(num);
    }
}
