def activity_selection(start, end):
    if not start or not end:
        return 0
    activities = sorted(zip(start, end), key=lambda x: x[1])
    count = 1
    last_end = activities[0][1]
    for s, f in activities[1:]:
        if s >= last_end:
            count += 1
            last_end = f
    return count


start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]
result = activity_selection(start, end)
print(f"Maximum activities: {result}")
