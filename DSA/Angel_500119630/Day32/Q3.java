public class Q3{
    public static void main(String[] args) {
        int[] arr = {4, 5, 6};
        int xor = 0;

        for (int num : arr) {
            xor ^= num;
        }
        System.out.println("XOR of all elements is: " + xor);
    }
}
