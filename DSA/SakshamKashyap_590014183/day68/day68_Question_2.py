import heapq
from collections import Counter

def rearrange_string(s):
	freq = Counter(s)
	max_heap = [(-count, char) for char, count in freq.items()]
	heapq.heapify(max_heap)
	prev = (0, '')
	result = []
	while max_heap:
		count, char = heapq.heappop(max_heap)
		result.append(char)
		if prev[0] < 0:
			heapq.heappush(max_heap, prev)
		count += 1
		prev = (count, char)
	res = ''.join(result)
	return res if len(res) == len(s) else ''

# Example usage:
if __name__ == "__main__":
	print(rearrange_string("aab"))  # Output: "aba"
	print(rearrange_string("aaab"))  # Output: ""
