import java.util.*;

public class Q1 {

    public static void displayQueue(Queue<Integer> queue) {
        int size = queue.size();

        for (int i = 0; i < size; i++) {
            int val = queue.poll();    
            System.out.print(val + " "); 
            queue.offer(val);        
        }

        System.out.println(); 
    }

    // Demo
    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(10, 20, 30));
        displayQueue(queue1); 

        Queue<Integer> queue2 = new LinkedList<>(List.of(5, 15));
        displayQueue(queue2); 
    }
}
