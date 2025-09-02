1. Identify the incorrect sorting criterio.
The bug comes from the sorting step. The items are currently being sorted by their value (items.sort(key=lambda x: x[0], reverse=True)),
but the Fractional Knapsack problem must be solved by sorting according to value-to-weight ratio.

2. Explain why sorting by value  instead of value/weight ratio.
Sorting by value alone is wrong because a high-value item may also have a very high weight, which could quickly consume the capacity without maximizing the overall value. 
The greedy choice for this problem is always the item with the highest value per unit weight.

3. What should be the correct sorting approach? 
items.sort(key=lambda x: x[2], reverse=True)
his way, items are chosen in descending order of their value-to-weight ratio, 
ensuring the maximum value is packed into the knapsack.
