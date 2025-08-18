def min_remove_for_no_overlap(intervals):
    if not intervals:
        return 0
    n = len(intervals)
    # Sort by end time
    intervals = sorted(intervals, key=lambda x: x)
    max_remaining = 0
    last_end = float('-inf')
    for start, end in intervals:
        if start >= last_end:
            max_remaining += 1
            last_end = end
    removes = n - max_remaining
    return removes, max_remaining

# Example 1
intervals = [(1, 2), (2, 3), (3, 4), (1, 3)]
removes, remaining = min_remove_for_no_overlap(intervals)
print(f"Remove {removes} → Remaining {remaining}")  # Output: Remove 1 → Remaining 3

# Example 2
intervals = [(1, 2), (1, 2), (1, 2)]
removes, remaining = min_remove_for_no_overlap(intervals)
print(f"Remove {removes} → Remaining {remaining}")  # Output: Remove 2 → Remaining 1
