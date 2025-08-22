import heapq

def kth_largest_sum_of_subarray(arr, k):
    n = len(arr)
    min_heap = []

    # Generate prefix sums to calculate subarray sums faster
    prefix = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix[i] = prefix[i - 1] + arr[i - 1]

    # Generate all subarray sums
    for start in range(n):
        for end in range(start + 1, n + 1):
            sub_sum = prefix[end] - prefix[start]

            # Push to heap
            heapq.heappush(min_heap, sub_sum)

            # Keep only k largest
            if len(min_heap) > k:
                heapq.heappop(min_heap)

    return min_heap[0]

try:
    arr = list(map(int, input("Enter the elements of the array separated by spaces : ").split()))
    k = int(input("Enter the value of k : "))
    print(kth_largest_sum_of_subarray(arr, k))
except:
    print("Invalid input. Please try with a valid input.") 
