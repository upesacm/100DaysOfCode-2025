# Implement hash-based frequency counting to analyze element occurrences and generate comprehensive frequency distribution from queue data.
input_str = input("Enter integers separated by spaces: ")

queue = [int(x) for x in input_str.split()]

frequency = {}

for num in queue:
    if num in frequency:
        frequency[num] += 1
    else:
        frequency[num] = 1

print(frequency)
