def profit_job_scheduling(jobs):
    # Sorting the jobs by profit.
    jobs.sort(key = lambda x : x[2], reverse = True)

    # Finding the maximum deadline.
    max_deadline = max(job[1] for job in jobs)

    # Initialize slots (-1 means free)
    slots = [-1] * (max_deadline + 1)

    total_profit = 0
    job_count = 0

    # Assign the jobs greedily.
    for job_id, deadline, profit in jobs:
        # Try to schedule at the latest possible slot before dealine
        for d in range(deadline, 0, -1):
            if slots[d] == -1:
                slots[d] = job_id
                total_profit += profit
                job_count += 1
                break

    return job_count, total_profit

try:
    n = int(input("Enter the number of jobs : "))
    jobs = []
    print("Enter the job_id, its deadline and its profit separated by spaces : ")
    for i in range(n):
        jobs.append(tuple(map(int, input().split())))    
    count, total_profit = profit_job_scheduling(jobs)
    print(f"{count} jobs, Profit : {total_profit}")
except:
    print("Invalid input. Please try with a valid input.") 
