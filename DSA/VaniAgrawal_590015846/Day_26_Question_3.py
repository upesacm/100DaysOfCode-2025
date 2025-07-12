#Sort a linked list containing only 0s, 1s, and 2s using efficient partitioning techniques without extra space.
elements = list(map(int, input("Enter linked list of 0s, 1s, and 2s: ").split()))

low = 0
mid = 0
high = len(elements) - 1

while mid <= high:
    if elements[mid] == 0:
        elements[low], elements[mid] = elements[mid], elements[low]
        low += 1
        mid += 1
    elif elements[mid] == 1:
        mid += 1
    else: 
        elements[mid], elements[high] = elements[high], elements[mid]
        high -= 1

print(" -> ".join(map(str, elements)))
