import java.util.*;

public class Q2 {
    public static String rearrangeString(String s) {
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Map.Entry<Character, Integer>> maxHeap =
                new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        maxHeap.addAll(freqMap.entrySet());

        StringBuilder result = new StringBuilder();
        Map.Entry<Character, Integer> prev = null;

        while (!maxHeap.isEmpty()) {
            Map.Entry<Character, Integer> curr = maxHeap.poll();
            result.append(curr.getKey());
            curr.setValue(curr.getValue() - 1);

            if (prev != null && prev.getValue() > 0) {
                maxHeap.offer(prev);
            }
            prev = curr;
        }

        return result.length() == s.length() ? result.toString() : "";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(rearrangeString(s));
        sc.close();
    }
}
