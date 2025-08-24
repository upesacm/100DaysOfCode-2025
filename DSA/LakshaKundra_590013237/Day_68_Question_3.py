def maxSum(nums,k):
    nums.sort()
    i=0
    while k>0 and i<len(nums) and nums[i]<0:
        nums[i]=-nums[i]
        i+=1
        k-=1
    nums.sort()
    if k%2: nums[0]=-nums[0]
    return sum(nums)

print(maxSum([4,2,3],1))
print(maxSum([3,-1,0,2],3))
