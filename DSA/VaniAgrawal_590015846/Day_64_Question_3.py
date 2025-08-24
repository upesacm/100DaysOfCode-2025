#Implement greedy job scheduling using profit-based selection with deadline management to achieve optimal job sequencing with maximum profit generation.
def job_scheduling(jobs):
    jobs.sort(key=lambda x: x[1], reverse=True)
    max_deadline = max(job[0] for job in jobs)
    slots = [-1] * (max_deadline + 1)
    profit, count = 0, 0
    for d, p in jobs:
        for t in range(d, 0, -1):
            if slots[t] == -1:
                slots[t] = p
                profit += p
                count += 1
                break
    return count, profit

n = int(input("Enter number of jobs: "))
jobs = []
for _ in range(n):
    d, p = map(int, input().split())
    jobs.append((d, p))
res = job_scheduling(jobs)
print(res[0], res[1])
