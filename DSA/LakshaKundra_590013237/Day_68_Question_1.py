def minJumps(arr):
    n=len(arr)
    if n<=1: return 0
    if arr[0]==0: return -1
    jumps=1
    maxReach=arr[0]
    step=arr[0]
    for i in range(1,n):
        if i==n-1: return jumps
        maxReach=max(maxReach,i+arr[i])
        step-=1
        if step==0:
            jumps+=1
            if i>=maxReach: return -1
            step=maxReach-i
    return -1

print(minJumps([2,3,1,1,4]))
print(minJumps([1,1,1,1]))
