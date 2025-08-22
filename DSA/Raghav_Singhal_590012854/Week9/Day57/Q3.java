import java.util.*;

public class Q3 {

    static class Element {
        int value;
        int arrayIndex;
        int elementIndex; 

        Element(int value, int arrayIndex, int elementIndex) {
            this.value = value;
            this.arrayIndex = arrayIndex;
            this.elementIndex = elementIndex;
        }
    }
    public static List<Integer> mergeKSortedArrays(List<List<Integer>> arrays) {
        List<Integer> result = new ArrayList<>();
        PriorityQueue<Element> minHeap = new PriorityQueue<>(Comparator.comparingInt(e -> e.value));

        for (int i = 0; i < arrays.size(); i++) {
            if (!arrays.get(i).isEmpty()) {
                minHeap.offer(new Element(arrays.get(i).get(0), i, 0));
            }
        }
        while (!minHeap.isEmpty()) {
            Element current = minHeap.poll();
            result.add(current.value);

            int nextIndex = current.elementIndex + 1;
            if (nextIndex < arrays.get(current.arrayIndex).size()) {
                minHeap.offer(new Element(
                        arrays.get(current.arrayIndex).get(nextIndex),
                        current.arrayIndex,
                        nextIndex
                ));
            }
        }

        return result;
    }

    public static void main(String[] args) {
        List<List<Integer>> arrays = Arrays.asList(
                Arrays.asList(1, 4, 7),
                Arrays.asList(2, 5, 8),
                Arrays.asList(3, 6, 9)
        );

        System.out.println(mergeKSortedArrays(arrays));
        // Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
    }
}
