class queue:
    def __init__(self):
        self.data = []
    def enqueue(self,data):
        self.data.append(data)
    def dequeue(self):
        if self.data:
            return self.data.pop(0)
    def display(self):
        print("Queue:", self.data)
    def size(self):
        return len(self.data)
    def is_empty(self):
        if self.data == []:
            return True
        else:
            return False
q1 = queue()
n1 = int(input("Enter the number of elements in Queue1: "))
for i in range(n1):
    val1 = int(input(f"Enter the {i+1} element: "))
    q1.enqueue(val1)
q2 = queue()
n2 = int(input("Enter the number of elements in Queue2: "))
for j in range(n2):
    val2 = int(input(f"Input the value of the {j+1} element: "))
    q2.enqueue(val2)
if q1.size() != q2.size():
    print("No")
else:
    while not q1.is_empty() and not q2.is_empty():
        if q1.dequeue()!=q2.dequeue():
            print("No")
            break
    else:
        print("Yes")
