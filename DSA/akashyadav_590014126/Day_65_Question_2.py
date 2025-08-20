def max_chain_length(pairs):
    pairs.sort(key=lambda x: x[1])  
    count = 0
    current_end = float('-inf')
    
    for a, b in pairs:
        if a > current_end:
            count += 1
            current_end = b
            
    return count

# Example
print(max_chain_length([(1, 2), (2, 3), (3, 4)]))          