
public class Q1 {
    public static void main(String args[]) {
        int[] arr = {1, 4, 45, 6, 10, 8};
        int x = 16;
        System.out.println(pair(arr, x));
    }

    static boolean pair(int[] arr, int x) {
        for (int i = 0; i < arr.length-1; i++) {
            for (int j = i+1; j < arr.length; j++) {
                if(arr[i]+arr[j]==x)
                    return true;
            }
        }
        return false;
    }
}
