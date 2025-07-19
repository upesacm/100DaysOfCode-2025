import java.util.Scanner;
public class Day_34_Question_3 {
    // Solution 3
    public static boolean isBinaryPalindrome(int n){
        int left = numberOfBit(n)-1;
        int right = 0;
        while(left>right){
            int left_bit = (n >> left) & 1;
            int right_bit = (n >> right) & 1;
            if(left_bit!=right_bit) return false;
            left--;
            right++;
        }
        return true;
    }

    public static int numberOfBit(int n){
        int length = 0;
        while(n>0){
            length++;
            n>>=1;
        }
        return length;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Integer : ");
        int num = sc.nextInt();
        System.out.print(isBinaryPalindrome(num));
    }
}
