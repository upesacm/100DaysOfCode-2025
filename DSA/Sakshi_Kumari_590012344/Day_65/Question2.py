def max_chain_length(pairs):
    pairs.sort(key=lambda x: x[1])
    count = 0
    last_end = float('-inf')
    for a, b in pairs:
        if a > last_end:
            count += 1
            last_end = b
    return count
