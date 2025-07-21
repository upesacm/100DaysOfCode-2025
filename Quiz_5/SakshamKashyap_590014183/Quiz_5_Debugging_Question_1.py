def extract_unique_numbers(data):
    xor_total = 0
    for item in data:
        xor_total ^= item  # XOR of all values: duplicates cancel, leaves num1 ^ num2

    # Isolate a bit where the two unique numbers differ
    separator_bit = xor_total & -xor_total  # Finds the lowest differing bit

    first_unique = 0
    second_unique = 0
    for item in data:
        # BUGGY LINE — this was originally: if item & xor_total
        # That mistakenly checks many bits together instead of one
        if item & xor_total:  # Wrong condition
            first_unique ^= item
        else:
            second_unique ^= item

    return first_unique, second_unique


# What's wrong?
# Using item & xor_total is incorrect because xor_total may contain multiple set bits.
# This causes the grouping to split duplicates incorrectly.

# Proper fix:
# Use a single differentiating bit: separator_bit = xor_total & -xor_total
# That one bit is guaranteed to be different between the two unique numbers.

# It divides the array so:
# - Duplicates stay in the same group
# - The two different numbers fall into separate groups
# Then we XOR within each group to isolate them.