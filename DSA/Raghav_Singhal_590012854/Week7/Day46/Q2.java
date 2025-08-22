import java.util.*;

public class Q2 {

    public static void countEvenOdd(Queue<Integer> queue) {
        int size = queue.size();
        int evenCount = 0;
        int oddCount = 0;

        for (int i = 0; i < size; i++) {
            int val = queue.poll();

            if (val % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }

            queue.offer(val);
        }

        System.out.println("Even: " + evenCount + ", Odd: " + oddCount);
    }

    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(10, 15, 20, 25));
        countEvenOdd(queue1); 

        Queue<Integer> queue2 = new LinkedList<>(List.of(2, 4, 6, 8));
        countEvenOdd(queue2);  
    }
}
