import heapq

def max_sum_after_k_negations(nums, k):
    heapq.heapify(nums)

    for _ in range(k):
        smallest = heapq.heappop(nums)
        heapq.heappush(nums, -smallest)

    return sum(nums)
