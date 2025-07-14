public class Q3 {
    public static void main(String args[])
    {
        int Target= 27;
        System.out.println(sqRoot(Target));
    }
    public static int sqRoot(int n) 
    {
        if (n < 2) return n;

        int left= 1, right = n, ans = 0;

        while (left<= right) {
            int mid = left+ (right - left) / 2;
            
            if ((long)mid * mid == n) {
                return mid;
            } else if ((long)mid * mid < n) {
                ans = mid;
                left= mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
}