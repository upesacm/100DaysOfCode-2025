def max_meetings(start, end):
    meetings = sorted(zip(start, end), key=lambda x: x[1])
    count, last_end = 0, -1
    for s, e in meetings:
        if s > last_end:
            count += 1
            last_end = e
    return count

start = list(map(int, input("Enter start times separated by space: ").split()))
end = list(map(int, input("Enter end times separated by space: ").split()))
print(max_meetings(start, end))
