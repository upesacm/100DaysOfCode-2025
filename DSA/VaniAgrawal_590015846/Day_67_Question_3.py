# Max Number of Non-overlapping Meetings
n = int(input())
start = list(map(int, input().split()))
end = list(map(int, input().split()))
meetings = sorted(zip(start, end), key=lambda x: x[1])
count, last_end = 0, -1
for s, e in meetings:
    if s >= last_end:
        count += 1
        last_end = e
print(count)
