def maxMeetings(intervals):
    intervals.sort(key=lambda x: x[1])
    count = 0
    end_time = -1
    for start, end in intervals:
        if start >= end_time:
            count += 1
            end_time = end
    return count
