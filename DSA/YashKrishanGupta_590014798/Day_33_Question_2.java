import java.util.Scanner;
public class Day_33_Question_2 {

    // Solution 2
    public static int clearRightmostBit(int n){
        n &= (n-1);
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Integer : ");
        int num = sc.nextInt();
        num = clearRightmostBit(num);
        System.out.print(num);
    }
}
