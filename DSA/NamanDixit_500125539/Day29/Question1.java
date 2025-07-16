import java.util.*;

public class Question1 {

    static boolean isODD(long n) {
        if ((n ^ 1) == (n - 1))
            return true;
        else
            return false;
    }

    static boolean isEVEN(long n) {
        if ((n ^ 1) == (n + 1))
            return true;
        else
            return false;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if (isODD(n))
            System.out.print("ODD");
        else if (isEVEN(n))
            System.out.print("EVEN");
    }
}
