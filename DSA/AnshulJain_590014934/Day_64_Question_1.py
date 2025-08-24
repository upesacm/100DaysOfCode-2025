n=int(input())
start=list(map(int,input().split()))
end=list(map(int,input().split()))
activities=sorted(zip(start,end),key=lambda x:x[1])
count=1
last_end=activities[0][1]
for i in range(1,n):
    if activities[i][0]>=last_end:
        count+=1
        last_end=activities[i][1]
print(count)
