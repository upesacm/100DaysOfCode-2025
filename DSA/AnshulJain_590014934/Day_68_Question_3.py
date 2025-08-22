import heapq
nums = list(map(int, input( "Enter The number:-").split()))# taking input from the user 
k = int(input("Enter The K value "))
heapq.heapify(nums)
for _ in range(k):
    x = heapq.heappop(nums)
    heapq.heappush(nums, -x)
print(sum(nums))
#for example :
#input :- num= 4 2 3
#   k=1
#output = 5