import heapq

def median_in_a_stream():
    """
    Finds the median of a stream of numbers using a dual-heap approach.
    """
    try:
        stream_str = input("Enter the stream of integers separated by spaces (e.g., 5 15 1 3): ")
        stream = [int(x) for x in stream_str.split()]

        min_heap = []  # Stores the larger half
        max_heap = []  # Stores the smaller half (using negative values)
        medians = []

        for num in stream:
            # Push to the max-heap first
            heapq.heappush(max_heap, -num)
            # Balance by moving the max element of max_heap to min_heap
            heapq.heappush(min_heap, -heapq.heappop(max_heap))

            # Re-balance the heaps to maintain the size property
            if len(max_heap) < len(min_heap):
                heapq.heappush(max_heap, -heapq.heappop(min_heap))

            # Calculate and store the median
            if len(max_heap) == len(min_heap):
                median = (-max_heap[0] + min_heap[0]) / 2.0
            else:
                median = -max_heap[0]

            medians.append(median)

        print("Output:", ", ".join(str(m) for m in medians))

    except ValueError:
        print("Invalid input. Please enter a stream of integers.")

# Example usage
median_in_a_stream()
