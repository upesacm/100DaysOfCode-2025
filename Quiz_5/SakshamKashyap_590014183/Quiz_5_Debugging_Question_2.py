def is_valid_power_of_two(x):
    # Original mistake: Didn’t check for negatives or zero
    if x == 0:
        return False

    # The condition may incorrectly say True for negatives (like -8), which isn't valid
    if (x & (x - 1)) == 0:
        return True
    return False


# Why it fails:
# Python represents negative numbers in binary with two's complement format.
# So -8 & -9 might result in 0, which wrongly passes the power-of-two test.

# Required fix:
# First ensure the number is strictly positive.
# Correct version:
# def is_valid_power_of_two(x):
#     if x <= 0:
#         return False
#     return (x & (x - 1)) == 0

def test_power_of_two(numbers):
    print("Power of Two Status:")
    for n in numbers:
        if is_valid_power_of_two(n):
            print(f"{n} → YES")
        else:
            print(f"{n} → NO")

# Example input to try
sample_input = [0, 1, 2, 4, 6, -2, 8, 32, -8, 128, -1]
test_power_of_two(sample_input)