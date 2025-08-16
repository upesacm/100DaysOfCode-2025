import heapq

def kth_largest_subarray_sum(arr,k):
    min_heap=[]

    for start in range(len(arr)):
        current_sum=0
        for end in range(start,len(arr)):
            current_sum += arr[end]
            heapq.heappush(min_heap,current_sum)

            if len(min_heap)>k:
                heapq.heappop(min_heap)
    
    return min_heap[0]

#example
print(kth_largest_subarray_sum([45,55,67,76,88,91,98,100],3))