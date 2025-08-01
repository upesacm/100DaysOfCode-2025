import java.util.*;

public class Q1 {

    public static int sumQueue(Queue<Integer> queue) {
        int size = queue.size();
        int sum = 0;

        for (int i = 0; i < size; i++) {
            int val = queue.poll();  
            sum += val;              
            queue.offer(val);       
        }

        return sum;
    }

    // Demo
    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(10, 20, 30));
        System.out.println("Sum: " + sumQueue(queue1));  

        Queue<Integer> queue2 = new LinkedList<>(List.of(5, 15, 25));
        System.out.println("Sum: " + sumQueue(queue2));  
    }
}
