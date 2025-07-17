public class Q2{
    public static void main(String[] args) {
        int[] arr = {5, 1, 1, 5, 7};
        int result = 0;

        for (int num : arr) {
            result ^= num; 
        }
        System.out.println("The unique element is: " + result);
    }
}
