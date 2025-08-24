# 1. Identify the incorrect sorting criterion:
#    The original code sorts items by their value (x[0]), but the correct greedy approach is to sort by value-to-weight ratio (x[2]).
#
# 2. Why sorting by value is incorrect:
#    Sorting by value alone ignores how much weight is required to obtain that value. This can lead to picking heavy items with high value but poor value/weight efficiency, resulting in a suboptimal total value for the knapsack.
#
# 3. Correct sorting approach:
#    Sort items by their value-to-weight ratio in descending order. This ensures we always pick the item (or fraction) that gives the most value per unit of weight, maximizing the total value within the capacity constraint.

def fractional_knapsack(weights, values, capacity):
	n = len(weights)
	items = []
	for i in range(n):
		ratio = values[i] / weights[i]
		items.append((values[i], weights[i], ratio))
	# Corrected: sort by value-to-weight ratio
	items.sort(key=lambda x: x[2], reverse=True)
	total_value = 0
	current_weight = 0
	for value, weight, ratio in items:
		if current_weight + weight <= capacity:
			current_weight += weight
			total_value += value
		else:
			remaining_capacity = capacity - current_weight
			fraction = remaining_capacity / weight
			total_value += value * fraction
			break
	return total_value

# Test case:
weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
result = fractional_knapsack(weights, values, capacity)
print(f"Maximum value: {result}")
