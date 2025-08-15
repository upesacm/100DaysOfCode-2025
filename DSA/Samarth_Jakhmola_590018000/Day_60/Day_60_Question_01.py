import heapq

def sort_k_sorted_array(arr, k):
    n = len(arr)
    result = []

    # Step 1 : Create a minimum heap from first k + 1 elements
    heap = arr[:k + 1]
    heapq.heapify(heap)

    # Step 2 : Process the remaining elements
    for i in range(k + 1, n):
        smallest = heapq.heappop(heap)
        result.append(smallest)
        heapq.heappush(heap, arr[i])

    # Step 3 : Pop remaining elements from heap
    while heap:
        result.append(heapq.heappop(heap))

    return result

try:
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    k = int(input("Enter the value of k : "))
    print(sort_k_sorted_array(arr, k))
except:
    print("Invalid input. Please try with a valid input.")
