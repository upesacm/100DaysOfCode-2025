def max_activities(start, end):
    n = len(start)
    activities = sorted(zip(start, end), key=lambda x: x[1])
    selected = []
    last_end = -1

    for s, e in activities:
        if s >= last_end:
            selected.append((s, e))
            last_end = e

    return selected
