queue = list(map(int, input("Enter the Queue:").split()))
element = int(input("Enter the element to insert at front: "))
queue = [element] + queue
print(queue)
#for example:
#input:- 1 2 3 4 5
# insert:- 0
#output:- [0, 1, 2, 3, 4, 5]