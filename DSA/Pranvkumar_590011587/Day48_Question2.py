def all_elements_unique(queue):
    seen = set()
    for item in queue:
        if item in seen:
            return False
        seen.add(item)
    return True

# Examples:
print(all_elements_unique([1,2,3,4]))    
print(all_elements_unique([1,2,2,3]))      