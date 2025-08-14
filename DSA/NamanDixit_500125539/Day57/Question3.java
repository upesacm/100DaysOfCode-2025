import java.util.*;

public class Question3 {

    static class Node implements Comparable<Node> {
        int value;
        int arrayIndex;
        int elementIndex;

        Node(int value, int arrayIndex, int elementIndex) {
            this.value = value;
            this.arrayIndex = arrayIndex;
            this.elementIndex = elementIndex;
        }

        public int compareTo(Node other) {
            return Integer.compare(this.value, other.value);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine().trim(); // Read full line like [[1, 3], [2, 4], [5, 6]]

        // Remove [[, ]], split into array groups
        input = input.substring(2, input.length() - 2);
        String[] parts = input.split("\\], \\[");

        List<int[]> arrays = new ArrayList<>();
        for (String part : parts) {
            String[] nums = part.split(",\\s*");
            int[] arr = new int[nums.length];
            for (int i = 0; i < nums.length; i++) {
                arr[i] = Integer.parseInt(nums[i]);
            }
            arrays.add(arr);
        }

        PriorityQueue<Node> minHeap = new PriorityQueue<>();

        for (int i = 0; i < arrays.size(); i++) {
            if (arrays.get(i).length > 0) {
                minHeap.add(new Node(arrays.get(i)[0], i, 0));
            }
        }

        List<Integer> merged = new ArrayList<>();
        while (!minHeap.isEmpty()) {
            Node node = minHeap.poll();
            merged.add(node.value);
            int nextIdx = node.elementIndex + 1;
            if (nextIdx < arrays.get(node.arrayIndex).length) {
                minHeap.add(new Node(arrays.get(node.arrayIndex)[nextIdx], node.arrayIndex, nextIdx));
            }
        }

        System.out.println(merged);
    }
}
