
import java.util.*;

public class Question3 {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number:");
        int n = sc.nextInt();
//>> Right shift operator
        int mul = n >> 1;
        System.out.println(mul);
        sc.close();

    }
}
