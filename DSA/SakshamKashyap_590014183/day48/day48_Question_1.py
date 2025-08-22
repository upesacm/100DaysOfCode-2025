def remove_all_occurrences(queue, x):
    return [element for element in queue if element != x]


queue1 = [1, 2, 3, 2, 4]
x1 = 2
updated_queue1 = remove_all_occurrences(queue1, x1)
print(updated_queue1)  

queue2 = [5, 5, 5]
x2 = 5
updated_queue2 = remove_all_occurrences(queue2, x2)
print(updated_queue2) 
