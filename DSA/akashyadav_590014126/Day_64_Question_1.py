def max_activities(start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])
    
    count = 0
    last_end_time = 0
    
    for s, e in activities:
        if s >= last_end_time:
            count += 1
            last_end_time = e
    
    return count

# Example
start = [16, 27, 38]
end = [27, 38, 49]
print(max_activities(start, end))
