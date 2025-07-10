def count_occurrences(linked_list, key):
    count = 0
    for num in linked_list:
        if num == key:
            count += 1
    return count


linked_list = [1, 2, 1, 2, 1, 3, 1]
key = 1
print(count_occurrences(linked_list, key))  