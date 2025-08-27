def job_scheduling(jobs):
    jobs.sort(key=lambda x: x[2], reverse=True)
    max_deadline = max(job[1] for job in jobs)
    slots = [False] * (max_deadline + 1)
    count, profit = 0, 0
    for job in jobs:
        for d in range(job[1], 0, -1):
            if not slots[d]:
                slots[d] = True
                count += 1
                profit += job[2]
                break
    return count, profit

print(job_scheduling([(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)]))
print(job_scheduling([(1, 2, 100), (2, 1, 19), (3, 2, 27)]))
