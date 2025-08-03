def count_occurrences(queue):
    frequency = {}
    for element in queue:
        if element in frequency:
            frequency[element] += 1
        else:
            frequency[element] = 1
    return frequency

queue1 = [1, 2, 2, 3, 1, 1]
print(count_occurrences(queue1))  

queue2 = [5, 5, 7, 8, 7]
print(count_occurrences(queue2))  
