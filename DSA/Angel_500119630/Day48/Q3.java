import java.util.*;

public class Q3 {
    public static Map<Integer, Integer> countOccurrences(Queue<Integer> queue) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : queue) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        return freq;
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(Arrays.asList(1, 2, 2, 3, 1, 1));
        System.out.println(countOccurrences(queue));
    }
}
