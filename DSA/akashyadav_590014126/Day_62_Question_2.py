import heapq

def k_closest_numbers(arr,target,k):
    max_heap=[]

    for num in arr:
        distance=abs(num-target)
        heapq.heappush(max_heap,(-distance,num))

        if len(max_heap)>k:
            heapq.heappop(max_heap)
    
    return [num for _,num in max_heap]

#example
print(k_closest_numbers([1,2,3,4,5,6,7],4,2))
