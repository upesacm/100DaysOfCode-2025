import java.util.*;
public class Q1 {
    public static int getMinInQueue(Queue<Integer> queue) {
        int min = Integer.MAX_VALUE;
        Queue<Integer> temp_list = new LinkedList<>(queue);
        while (!temp_list.isEmpty()) {
            int value = temp.poll();
            if (value < min) min = value;
        }
        return min;
    }
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(4, 2, 7, 1));
        System.out.println(getMinInQueue(queue));
    }
  
}
