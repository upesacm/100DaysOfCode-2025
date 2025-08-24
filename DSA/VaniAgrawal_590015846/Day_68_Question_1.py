# Min Jumps to Reach End
arr = list(map(int, input().split()))
jumps = 0
cur_end = 0
cur_farthest = 0
for i in range(len(arr) - 1):
    cur_farthest = max(cur_farthest, i + arr[i])
    if i == cur_end:
        jumps += 1
        cur_end = cur_farthest
print(jumps)
