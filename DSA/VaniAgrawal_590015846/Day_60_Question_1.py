import heapq

def sort_k_sorted_array():
    """
    Sorts a K-Sorted Array using a min-heap.
    """
    try:
        arr_str = input("Enter the array elements separated by spaces (e.g., 6 5 3 2 8 10 9): ")
        arr = [int(x) for x in arr_str.split()]
        k = int(input("Enter the value of k: "))

        n = len(arr)
        heap = []
        result = []

        # Push the first k+1 elements into the min-heap
        for i in range(min(k + 1, n)):
            heapq.heappush(heap, arr[i])

        # Process the remaining elements
        for i in range(k + 1, n):
            result.append(heapq.heappop(heap))
            heapq.heappush(heap, arr[i])

        # Add the remaining elements from the heap to the result
        while heap:
            result.append(heapq.heappop(heap))

        print("Output:", result)

    except ValueError:
        print("Invalid input. Please enter numbers for the array and an integer for k.")

# Example usage
sort_k_sorted_array()
