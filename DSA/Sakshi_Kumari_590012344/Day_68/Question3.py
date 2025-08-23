import heapq

def max_sum_after_k_negations(arr, k):
    heapq.heapify(arr)
    while k > 0:
        smallest = heapq.heappop(arr)
        heapq.heappush(arr, -smallest)
        k -= 1
    return sum(arr)
