import heapq
from collections import Counter

def rearrange_characters(string):
    frequency = Counter(string)
    max_heap = [(-count, ch) for ch , count in frequency.items()]
    heapq.heapify(max_heap)

    result = []
    prev = (0, '')   # (freq, char)

    while max_heap:
        count, ch = heapq.heappop(max_heap)
        result.append(ch)

        # If previous character still has some count, push it back
        if prev[0] < 0:
            heapq.heappush(max_heap, prev)

        # Update current char count
        count += 1  # because count is negative
        prev = (count, ch)

    rearranged = ''.join(result)
    return rearranged if len(rearranged) == len(string) else ""

try:
    string = input("Enter the string which needs to be rearranged : ")
    print(f"\"{rearrange_characters(string)}\"")
except:
    print("Invalid input. Please try with a valid input.")
