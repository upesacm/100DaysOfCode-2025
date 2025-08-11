import heapq

def k_largest_elements(arr, k):
    # Step 1 : Build a minimum heap with the first k elements
    heap = arr[:k]
    heapq.heapify(heap)

    # Step 2 : Process the remaining elements
    for num in arr[k:]:
        if num > heap[0]:  # If the element is larger than the smallest in heap, then exchange
            heapq.heapreplace(heap, num)

    # Step 3 : Return sorted result (largets to smallest)
    return sorted(heap, reverse = True)

try:
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    k = int(input("Enter the value of k : "))
    print(k_largest_elements(arr, k))
except:
    print("Invalid input. Please try with a valid input.")
