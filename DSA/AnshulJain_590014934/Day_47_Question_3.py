queue = list(map(int, input("Enetr The Queue:- ").split()))#Taking input by the  user 
if not queue:
    print("Queue is empty")
else:
    print("Front:", queue[0], "Rear:", queue[-1])
#for example:
#input:- 1 2 3 4 5
#output:- Front: 1 Rear: 5