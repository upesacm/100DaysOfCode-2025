# Incorrect sorting criterion:
items.sort(key=lambda x: x[0], reverse=True)


# The items are sorted by value only, instead of the value-to-weight ratio.

# Why this is wrong:

# An item with high value but very heavy weight may not be optimal to pick first.

# Example: In the test case, sorting by value prefers (120, 30) before (100, 20), which can lead to suboptimal fractional choices.

items.sort(key=lambda x: x[2], reverse=True)  # sort by ratio (value/weight)
