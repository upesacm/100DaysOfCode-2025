import java.util.*;

public class Question2 {

    // Function to rearrange string so no two adjacent chars are same
    public static String rearrangeString(String s) {
        // Count frequencies
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        // Max heap (priority queue) based on frequency
        PriorityQueue<Map.Entry<Character, Integer>> maxHeap =
                new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        maxHeap.addAll(freqMap.entrySet());

        StringBuilder result = new StringBuilder();
        Map.Entry<Character, Integer> prev = null;

        while (!maxHeap.isEmpty()) {
            Map.Entry<Character, Integer> current = maxHeap.poll();
            result.append(current.getKey());
            current.setValue(current.getValue() - 1);

            if (prev != null && prev.getValue() > 0) {
                maxHeap.offer(prev);
            }

            prev = current;
        }

        // If the result length doesn't match original -> not possible
        if (result.length() != s.length()) {
            return "Not possible to rearrange";
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String s = sc.nextLine();

        String result = rearrangeString(s);
        System.out.println(result);
    }
}
