import java.util.*;

public class Q2 {

    public static int Size(Queue<Integer> queue) {
    int count = 0;
    int size = queue.size();

    for (int i = 0; i < size; i++) {
        int val = queue.poll();
        count++;
        queue.offer(val); // Restore queue
    }

    return count;
}


    // Demo
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(1, 2, 3, 4));
        System.out.println(Size(queue));  // Output: 4
    }
}
