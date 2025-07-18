public class Q3 {
    public static int isolateRightmostSetBit(int n) {
        return n & -n;
    }

    public static void main(String[] args) {
        System.out.println(isolateRightmostSetBit(10)); 
    }
}
