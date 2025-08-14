import java.util.*;

public class MedianInStream {
    PriorityQueue<Integer> maxHeap; // smaller half
    PriorityQueue<Integer> minHeap; // larger half

    public MedianInStream() {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
    }

    public void addNum(int num) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.add(num);
        } else {
            minHeap.add(num);
        }

        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.add(maxHeap.poll());
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.add(minHeap.poll());
        }
    }

    public double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.peek() + minHeap.peek()) / 2.0;
        } else {
            return maxHeap.peek();
        }
    }

    public static void main(String[] args) {
        MedianInStream stream1 = new MedianInStream();
        int[] nums1 = {5, 15, 1, 3};
        for (int num : nums1) {
            stream1.addNum(num);
            System.out.print(stream1.findMedian() + " ");
        }
        System.out.println();

        MedianInStream stream2 = new MedianInStream();
        int[] nums2 = {1, 2, 3, 4, 5};
        for (int num : nums2) {
            stream2.addNum(num);
            System.out.print(stream2.findMedian() + " ");
        }
    }
}
