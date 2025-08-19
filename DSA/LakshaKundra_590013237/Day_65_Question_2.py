def max_chain(pairs):
    pairs.sort(key=lambda x: x[1])
    count, last_end = 0, float('-inf')
    for a, b in pairs:
        if a > last_end:
            count += 1
            last_end = b
    return count

print(max_chain([(5, 24), (15, 25), (27, 40), (50, 60)]))
print(max_chain([(1, 2), (2, 3), (3, 4)]))
