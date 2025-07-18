
import java.util.*;

public class Question1 {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first number: ");
        int n = sc.nextInt();
        System.out.println("Enter second number: ");
        int m = sc.nextInt();
        m = m ^ n;
        n=n^m;
        m=m^n;
        System.out.println("First number= "+n+" Second number= "+m);
    }
}
