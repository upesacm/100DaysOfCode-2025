import heapq
from collections import Counter

def top_k_frequent_elements():
    """
    Finds the k most frequent elements in a list using a min-heap.
    """
    try:
        arr_str = input("Enter the array elements separated by spaces (e.g., 1 1 1 2 2 3): ")
        arr = [int(x) for x in arr_str.split()]
        k = int(input("Enter the value of k: "))

        if k <= 0:
            print("k must be a positive integer.")
            return

        # Count the frequency of each element
        frequency_map = Counter(arr)

        min_heap = []
        for num, freq in frequency_map.items():
            if len(min_heap) < k:
                heapq.heappush(min_heap, (freq, num))
            else:
                if freq > min_heap[0][0]:
                    heapq.heappop(min_heap)
                    heapq.heappush(min_heap, (freq, num))

        # Extract the elements from the heap
        result = [num for freq, num in min_heap]
        
        print("Output:", result)

    except ValueError:
        print("Invalid input. Please enter numbers for the array and an integer for k.")

# Example usage
top_k_frequent_elements()
