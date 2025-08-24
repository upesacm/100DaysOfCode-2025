1.
The bug is in this line of code:
items.sort(key=lambda x: x[0], reverse=True)

2.
The greedy strategy for the Fractional Knapsack problem is based on the principle of maximizing the "value density" of the items you choose. 
By selecting items with the highest value-to-weight ratio first, you are prioritizing the items that give you the most value for each unit of weight they consume.

When the algorithm sorts by value alone, it ignores the weight of the items. This can lead to a suboptimal solution. 
The algorithm might greedily choose a high-value, heavy item that quickly fills up the knapsack, leaving little to no room for other items, 
even if those other items are more "efficient" in terms of value per unit of weight.
                                                                                                                                          
3.
def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    items = []

    for i in range(n):
        ratio = values[i] / weights[i]
        items.append((values[i], weights[i], ratio))

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
                                                                                                                                        
                                                                                                                                          
                                                                                                                                          
