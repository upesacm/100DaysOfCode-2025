
def max_profit(prices):
	min_price = float('inf')
	max_profit = 0
	for price in prices:
		if price < min_price:
			min_price = price
		elif price - min_price > max_profit:
			max_profit = price - min_price
	return max_profit

# Example usage:
if __name__ == "__main__":
	prices1 = [7, 1, 5, 3, 6, 4]
	print(max_profit(prices1))  # Output: 5
	prices2 = [7, 6, 4, 3, 1]
	print(max_profit(prices2))  # Output: 0
