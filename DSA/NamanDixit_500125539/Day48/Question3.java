import java.util.*;

public class Question3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            queue.offer(sc.nextInt());
        }

        Map<Integer, Integer> frequencyMap = new LinkedHashMap<>(); // preserves insertion order

        for (int num : queue) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Format output like {1: 3, 2: 2, 3: 1}
        StringBuilder sb = new StringBuilder("{");
        for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
            sb.append(entry.getKey()).append(": ").append(entry.getValue()).append(", ");
        }
        if (!frequencyMap.isEmpty()) {
            sb.setLength(sb.length() - 2); // remove last ", "
        }
        sb.append("}");

        System.out.println(sb.toString());
    }
}
