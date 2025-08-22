import heapq
from collections import Counter

def top_k_frequent_elements(arr, k):
    # Count frequency of each element
    frequency = Counter(arr)

    # Create a max heap using negative frequencies
    max_heap = [(-freq, num) for num, freq in frequency.items()]
    heapq.heapify(max_heap)

    # Extract top k elements 
    top_k = [heapq.heappop(max_heap)[1] for _ in range(k)]
    return top_k

try:
    arr = list(map(int, input("Enter the elements of the list : ").split()))
    k = int(input("Enter the value of k : "))
    print(top_k_frequent_elements(arr, k))
except:
    print("Invalid input. Please try with a valid input.")
