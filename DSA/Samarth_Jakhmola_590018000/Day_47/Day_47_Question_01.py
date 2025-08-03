def insert_element(queue, element):
    if element.isdigit():
        queue.append(int(element))
    else:
        queue.append(element)
    return queue

try:
    queue = []
    elements = list(map(str, input("Enter the elements of the queue : ").split()))
    for i in elements:
        if i.isdigit():
            queue.append(int(i))
        else:
            queue.append(i)
    element = input("Enter the element to be inserted : ")
    print(insert_element(queue, element))
except:
    print("Invalid input. Please try with a valid input.")
