import java.util.Scanner;
public class Day_29_Question_3 {
    // Solution 3
    public static int setIthBit(int n, int i){
        int bit_mask = 1<<i;
        n  |=  bit_mask;
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number and which bit to set : ");
        int num = sc.nextInt();
        int i = sc.nextInt();
        int new_num = setIthBit(num,i);
        System.out.print(new_num);
    }
}
