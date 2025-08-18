def job_scheduling(jobs, deadlines, profits):
    data = []
    for i in range(len(jobs)):
        data.append((jobs[i], deadlines[i], profits[i]))
    
    data.sort(key=lambda x: x[2], reverse=True)
    
    max_deadline = max(deadlines)
    slots = [None] * (max_deadline + 1)
    total_profit = 0
    result = []
    
    for job, d, p in data:
        for t in range(d, 0, -1):
            if slots[t] is None:
                slots[t] = job
                total_profit += p
                result.append(job)
                break
    
    return result, total_profit
