import java.util.Scanner;
public class Day_30_Question_2 {
    // Solution 2
    public static int toggleIthBit(int n, int i){
        int bit_mask = 1<<i;
        n  ^=  bit_mask;
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number and which bit to clear : ");
        int num = sc.nextInt();
        int i = sc.nextInt();
        int new_num = toggleIthBit(num,i);
        System.out.print(new_num);
    }
}
