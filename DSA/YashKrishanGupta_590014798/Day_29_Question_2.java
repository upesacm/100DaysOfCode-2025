import java.util.Scanner;
public class Day_29_Question_2{
    // Solution 2
    public static int getIthBit(int n, int i){
        int bit_mask = 1<<i;
        if((n & bit_mask) == 0) return 0;
        else return 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number and which bit to get : ");
        int num = sc.nextInt();
        int i = sc.nextInt();
        int bit  = getIthBit(num,i);
        System.out.print(bit);
    }
}
