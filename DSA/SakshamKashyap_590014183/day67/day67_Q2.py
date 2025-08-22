import heapq

def min_cost(ropes):
	heapq.heapify(ropes)
	total_cost = 0
	while len(ropes) > 1:
		first = heapq.heappop(ropes)
		second = heapq.heappop(ropes)
		cost = first + second
		total_cost += cost
		heapq.heappush(ropes, cost)
	return total_cost

# Example usage:
if __name__ == "__main__":
	print(min_cost([4, 3, 2, 6]))  # Output: 29
	print(min_cost([1, 2, 3, 4, 5]))  # Output: 33
