#items.sort(key=lambda x: x[0], reverse=True)
#It sorts by value (x[0])

#answer2
#The Fractional Knapsack Problem relies on choosing items that give the highest value per unit weight.
#If we sort by just value, we may pick a very heavy item with a high value but poor value density, which wastes capacity.

#answer3
#We must sort by value/weight ratio (x[2]) in descending order:
#items.sort(key=lambda x: x[2], reverse=True)
#That ensures we always pick the item (or fraction) with the highest value density first.


