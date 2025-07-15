import java.util.*;
public class Q2{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        System.out.print("Enter a position: ");
        int position = sc.nextInt();
        iBit(num, position);
    }
    public static void iBit(int num, int position){
        if((num & (1 << position)) != 0){
            System.out.println("1");
        } else {
            System.out.println("0");
        }
    }
}
