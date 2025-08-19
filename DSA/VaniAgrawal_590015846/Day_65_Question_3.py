# Implement greedy overlap elimination using earliest end time strategy to minimize task removal while achieving conflict-free scheduling with optimal retention.

intervals = []
n = int(input("Enter number of intervals: "))
for _ in range(n):
    s, e = map(int, input("Enter interval (start end): ").split())
    intervals.append((s, e))

intervals.sort(key=lambda x: x[1])
end = float('-inf')
keep = 0

for s, e in intervals:
    if s >= end:
        keep += 1
        end = e

print("Remove =", len(intervals) - keep, "→ Remaining =", keep)
