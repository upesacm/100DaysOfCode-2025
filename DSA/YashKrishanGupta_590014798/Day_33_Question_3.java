import java.util.Scanner;
public class Day11_Q3 {
    // Solution 3
    public static int isolateRightmostBit(int n){
        n &= -n;
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Integer : ");
        int num = sc.nextInt();
        num = isolateRightmostBit(num);
        System.out.print(num);
    }
}
