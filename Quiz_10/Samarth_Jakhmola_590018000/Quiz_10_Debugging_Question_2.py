#  1.  The bug in the sorting criteria is that the function sorts items by VALUE only which is wrong as it ignores weight.

#  2.  Sorting by value alone can select heavy items first, which may fill the knapsack quickly and reduce the total value. For example : 
#      a single heavy item with high value but poor value/weight ratio will prevent adding smaller, more efficient items.

#  3.  The correct approach to sort should be sorting by VALUE/WEGHT ratio in descending order (items with the best efficiency come first).

#      Here's the corrected version : 

#      def fractional_knapsack(weights, values, capacity):
#          n = len(weights)
#          items = []
#      
#          for i in range(n):
#              ratio = values[i] / weights[i]
#              items.append((values[i], weights[i], ratio))
#      
#          # Correct sorting: by ratio (3rd element), descending
#          items.sort(key=lambda x: x[2], reverse=True)
#      
#          total_value = 0
#          current_weight = 0
#      
#          for value, weight, ratio in items:
#              if current_weight + weight <= capacity:
#                  current_weight += weight
#                  total_value += value
#              else:
#                  remaining_capacity = capacity - current_weight
#                  fraction = remaining_capacity / weight
#                  total_value += value * fraction
#                  break
#      
#          return total_value
#      
#      
#      # Test case:
#      weights = [10, 20, 30]
#      values = [60, 100, 120]
#      capacity = 50
#      result = fractional_knapsack(weights, values, capacity)
#      print(f"Maximum value: {result}")
