import java.util.*;

public class Question3 {
    
    public static long sumOfElements(long[] a, int n) {
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        return sum;
    }
    
    public static long maximizeSum(long[] a, int n, int k) {
        Arrays.sort(a);
        int i;
        
        for (i = 0; i < n; i++) {
            if (a[i] < 0 && k > 0) {
                a[i] = -a[i];
                k--;
                continue;
            } else {
                break;
            }
        }
        
        if (i == n) {
            i = i - 1;
        }
        
        if (i == 0) {
            i = i + 1;
        }
        
        if (k % 2 == 0 || k == 0) {
            return sumOfElements(a, n);
        }
        
        if (Math.abs(a[i]) >= Math.abs(a[i - 1])) {
            i--;
        }
        
        a[i] = -a[i];
        
        return sumOfElements(a, n);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        
        long[] a = new long[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        
        System.out.print("Enter value of k: ");
        int k = sc.nextInt();
        
        long result = maximizeSum(a, n, k);
        System.out.println(result);
        
        sc.close();
    }
}
