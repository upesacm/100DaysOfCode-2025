import java.util.*;

public class Q2 {

    public static boolean areElementsUnique(Queue<Integer> queue) {
        Set<Integer> seen = new HashSet<>();
        for (int num : queue) {
            if (!seen.add(num)) {
                return false; 
            }
        }
        return true; 
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(List.of(1, 2, 3, 4));
        Queue<Integer> q2 = new LinkedList<>(List.of(1, 2, 3, 1));
        System.out.println("Queue q1 Unique? " + areElementsUnique(q1)); // true
        System.out.println("Queue q2 Unique? " + areElementsUnique(q2)); // false
    }
}