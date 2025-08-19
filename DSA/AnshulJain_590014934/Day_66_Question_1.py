n = int(input("Enter number of trains: "))
arr = list(map(int, input("Enter arrival times: ").split()))
dep = list(map(int, input("Enter departure times: ").split()))
arr.sort()
dep.sort()
i = j = 0
platforms = 0
needed = 0
while i < n and j < n:
    if arr[i] <= dep[j]:
        needed += 1
        platforms = max(platforms, needed)
        i += 1
    else:
        needed -= 1
        j += 1
print(platforms)
#for example:
# Input:
# Enter number of trains: 3
# Enter arrival times: 100 200 300
# Enter departure times: 150 250 350
# Output:1