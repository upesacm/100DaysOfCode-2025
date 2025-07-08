# Remove duplicate nodes from a sorted linked list while maintaining proper node connections.
elements = input("Enter sorted linked list elements separated by space: ").split()

linked_list = [int(x) for x in elements]

def remove_duplicates(lst):
    if not lst:
        return []

    result = [lst[0]] 

    for i in range(1, len(lst)):
        if lst[i] != lst[i-1]:  
            result.append(lst[i])

    return result

unique_list = remove_duplicates(linked_list)

print(" -> ".join(map(str, unique_list)))
