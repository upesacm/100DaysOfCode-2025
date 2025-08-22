import java.util.*;

public class Q3 {

    public static Map<Integer, Integer> countFrequencies(Queue<Integer> queue) {
        Map<Integer, Integer> freqMap = new HashMap<>();

        for (int num : queue) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        return freqMap;
    }
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>(List.of(1, 2, 2, 3, 1, 2, 4));

        Map<Integer, Integer> result = countFrequencies(q);
        System.out.println("Frequency Distribution:");
        for (Map.Entry<Integer, Integer> entry : result.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
    }
}