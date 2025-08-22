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
        Queue<Integer> queue = new LinkedList<>(Arrays.asList(1, 2, 3, 4));
        System.out.println(areElementsUnique(queue));
    }
}
