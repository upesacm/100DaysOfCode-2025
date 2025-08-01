import java.util.*;

public class EvenOddCount {
    public static int[] countEvenOdd(Queue<Integer> queue) {
        int even = 0, odd = 0;
        for (int val : queue) {
            if (val % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return new int[]{even, odd};
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(1, 2, 3, 4, 5));
        int[] result1 = countEvenOdd(q1);
        System.out.println("Even: " + result1[0] + ", Odd: " + result1[1]); // Output: Even: 2, Odd: 3

        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(6, 8, 10));
        int[] result2 = countEvenOdd(q2);
        System.out.println("Even: " + result2[0] + ", Odd: " + result2[1]); // Output: Even: 3, Odd: 0
    }
}
