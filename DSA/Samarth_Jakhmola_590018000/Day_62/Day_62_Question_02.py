import heapq

def k_closest_numbers(arr, target, k):
    # Heap stores (distance, value)
    heap = []

    for num in arr:
        dist = abs(num - target)
        heapq.heappush(heap, (dist, num))

    # Extract k closest numbers
    result = [heapq.heappop(heap)[1] for _ in range(min(k, len(heap)))] 
    result.sort()  # Sort for consistent output
    return result 

try:
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    target = int(input("Enter the value of the target : "))
    k = int(input("Enter the value of k : "))
    print(k_closest_numbers(arr, target, k))
except:
    print("Invalid input. Please try with a valid input.") 
