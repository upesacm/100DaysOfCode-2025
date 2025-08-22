def are_all_unique(queue):
    seen = set()
    for element in queue:
        if element in seen:
            return False
        seen.add(element)
    return True


print(are_all_unique([1, 2, 3, 4]))    
print(are_all_unique([1, 2, 2, 3]))    
