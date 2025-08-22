
def max_meetings(start, end):
	meetings = sorted(zip(start, end), key=lambda x: x[1])
	count = 0
	last_end = -1
	for s, e in meetings:
		if s > last_end:
			count += 1
			last_end = e
	return count

# Example usage:
if __name__ == "__main__":
	start = [1, 3, 0, 5, 8, 5]
	end = [2, 4, 6, 7, 9, 9]
	print(max_meetings(start, end))  # Output: 4
