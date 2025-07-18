public class Q2 {
    public static int clearRightmostSetBit(int n) {
        return n & (n - 1);
    }

    public static void main(String[] args) {
        System.out.println(clearRightmostSetBit(12)); 
        
    }
}
