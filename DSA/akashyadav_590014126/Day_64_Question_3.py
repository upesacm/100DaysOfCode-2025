def job_scheduling(jobs):
    jobs.sort(key=lambda x: x[2], reverse=True)
    
    max_deadline = max(job[1] for job in jobs)
    
    slots = [False] * (max_deadline + 1)
    total_profit = 0
    job_count = 0
    
    for job_id, deadline, profit in jobs:
        for slot in range(deadline, 0, -1):
            if not slots[slot]:
                slots[slot] = True
                total_profit += profit
                job_count += 1
                break
    
    return job_count, total_profit

# Example
jobs = [(1, 2, 100), (2, 1, 19), (3, 2, 27)]
count, profit = job_scheduling(jobs)
print(f"{count} jobs, Profit: {profit}")  