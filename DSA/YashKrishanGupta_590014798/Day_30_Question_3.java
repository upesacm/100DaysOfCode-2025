import java.util.Scanner;
public class Day_30_Question_3 {
    // Solution 3
    public static int countSetBits(int n){
        int count = 0;
        while(n>0){
            if((n&1)==1) count++;
            n>>=1;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int num = sc.nextInt();
        int count = countSetBits(num);
        System.out.print("Count of set bits : ");
        System.out.print(count);
    }
}
