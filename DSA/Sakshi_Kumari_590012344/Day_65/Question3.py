def min_removals(tasks):
    tasks.sort(key=lambda x: x[1])
    count = 0
    last_end = float('-inf')
    for s, e in tasks:
        if s >= last_end:
            count += 1
            last_end = e
    return len(tasks) - count
