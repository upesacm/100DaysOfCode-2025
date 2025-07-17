public class question2 {
    public static void main(String[] args) {
        int[] arr = {2, 3, 2};

        int result = 0;
        for (int num : arr) {
            result ^= num;
        }

        System.out.println("The non-repeating element is: " + result);
    }
}
