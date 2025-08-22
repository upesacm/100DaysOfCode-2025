def max_chain_length(pairs):
    pairs.sort(key=lambda x: x[1])  # sort by second element
    count = 0
    last_end = float('-inf')

    for a, b in pairs:
        if a > last_end:
            count += 1
            last_end = b
    return count

print("Max chain length:", max_chain_length([(5, 24), (15, 25), (27, 40), (50, 60)]))  
print("Max chain length:", max_chain_length([(1, 2), (2, 3), (3, 4)]))               
