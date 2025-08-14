import heapq

def top_k_frequent(nums, k):
    freq_map = {}
    for n in nums:
        if n in freq_map:
            freq_map[n] += 1
        else:
            freq_map[n] = 1

    heap = []
    for num, freq in freq_map.items():
        heapq.heappush(heap, (freq, num))
        if len(heap) > k:
            heapq.heappop(heap)

    result = []
    while heap:
        result.append(heapq.heappop(heap)[1])
    return result[::-1]
