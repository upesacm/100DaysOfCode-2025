def all_elements_unique(queue):
    return len(queue) == len(set(queue))

print(all_elements_unique([1, 2, 3, 4]))
print(all_elements_unique([1, 2, 2, 3]))
