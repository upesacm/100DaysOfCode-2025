def maximum_chain_of_pairs(pairs):
    pairs.sort(key = lambda x : x[1])    # Sorting the pairs according to the second element.

    chain_length = 1
    last_end = pairs[0][1]
    
    for i in range(1, len(pairs)):
        if pairs[i][0] > last_end:
            chain_length += 1
            last_end = pairs[i][1]

    return chain_length

try:
    n = int(input("Enter the number of pairs : "))
    pairs = []
    print("Enter the pairs one at a time, separated by spaces : ")
    for i in range(n):
        pairs.append(tuple(map(int, input().split())))
    print(maximum_chain_of_pairs(pairs))
except:
    print("Invalid input. Please try with a valid input.")
