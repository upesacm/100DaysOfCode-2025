def job_scheduling(jobs):
    if not jobs:
        return (0, 0)
    
    # Sort jobs by profit descending (job_id, deadline, profit)
    jobs = sorted(jobs, key=lambda x: x[2], reverse=True)
    
    # Find max deadline to create slot array
    max_deadline = max(job for job in jobs)
    slots = [False] * (max_deadline + 1)  # slots to slots[max_deadline], False means available
    
    num_jobs = 0
    total_profit = 0
    
    for job_id, deadline, profit in jobs:
        # Try to find the latest available slot <= deadline
        for slot in range(deadline, 0, -1):
            if not slots[slot]:
                slots[slot] = True
                num_jobs += 1
                total_profit += profit
                break
    
    return (num_jobs, total_profit)

# Example 1
jobs = [(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)]
num_jobs, profit = job_scheduling(jobs)
print(f"{num_jobs} jobs, Profit: {profit}")  # Output: 2 jobs, Profit: 60

# Example 2
jobs = [(1, 2, 100), (2, 1, 19), (3, 2, 27)]
num_jobs, profit = job_scheduling(jobs)
print(f"{num_jobs} jobs, Profit: {profit}")  # Output: 2 jobs, Profit: 127
