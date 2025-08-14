import java.util.*;

class Element {
    int value, arrayIndex, elementIndex;
    Element(int value, int arrayIndex, int elementIndex) {
        this.value = value;
        this.arrayIndex = arrayIndex;
        this.elementIndex = elementIndex;
    }
}

public class MergeKSortedArrays {
    public static List<Integer> mergeKSorted(int[][] arrays) {
        PriorityQueue<Element> minHeap = new PriorityQueue<>(Comparator.comparingInt(e -> e.value));
        List<Integer> result = new ArrayList<>();

        // insert first element from each array
        for (int i = 0; i < arrays.length; i++) {
            if (arrays[i].length > 0) {
                minHeap.add(new Element(arrays[i][0], i, 0));
            }
        }

        while (!minHeap.isEmpty()) {
            Element curr = minHeap.poll();
            result.add(curr.value);

            int nextIndex = curr.elementIndex + 1;
            if (nextIndex < arrays[curr.arrayIndex].length) {
                minHeap.add(new Element(arrays[curr.arrayIndex][nextIndex], curr.arrayIndex, nextIndex));
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[][] arr1 = {{1, 3}, {2, 4}, {5, 6}};
        int[][] arr2 = {{1, 4, 5}, {1, 3, 4}, {2, 6}};

        System.out.println(mergeKSorted(arr1)); // [1, 2, 3, 4, 5, 6]
        System.out.println(mergeKSorted(arr2)); // [1, 1, 2, 3, 4, 4, 5, 6]
    }
}
