import java.util.*;

public class CountOccurrences {
    public static Map<Integer, Integer> countFrequencies(Queue<Integer> queue) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        int size = queue.size();

        for (int i = 0; i < size; i++) {
            int val = queue.remove();
            freqMap.put(val, freqMap.getOrDefault(val, 0) + 1);
            queue.add(val); // maintain queue order
        }

        return freqMap;
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(1, 2, 2, 3, 1, 1));
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(5, 5, 7, 8, 7));

        System.out.println("Frequencies in q1: " + countFrequencies(q1)); // {1=3, 2=2, 3=1}
        System.out.println("Frequencies in q2: " + countFrequencies(q2)); // {5=2, 7=2, 8=1}
    }
}
