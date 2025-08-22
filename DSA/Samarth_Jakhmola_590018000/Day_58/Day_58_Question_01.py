import heapq

def kth_smallest(arr, k):
    # Converting the array into a minimum heap
    heapq.heapify(arr)

    # Extract minimum k - 1 times
    for _ in range(k - 1):
        heapq.heappop(arr)

    # The next pop gives kth smallest 
    return heapq.heappop(arr)

try: 
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    k = int(input("Enter the value of k : "))
    print(kth_smallest(arr, k))
except:
    print("Invalid input. Please try with a valid input.")
