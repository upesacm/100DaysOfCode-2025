def max_chain_pairs(pairs):
    if not pairs:
        return 0
    # Sort by second element (b)
    pairs = sorted(pairs, key=lambda x: x[1])
    count = 1  # Start with the first pair
    last_b = pairs
    for a, b in pairs[1:]:
        if a > last_b:
            count += 1
            last_b = b
    return count

# Example 1
pairs = [(5, 24), (15, 25), (27, 40), (50, 60)]
print(max_chain_pairs(pairs))  # Output: 3

# Example 2
pairs = [(1, 2), (2, 3), (3, 4)]
print(max_chain_pairs(pairs))  # Output: 2
