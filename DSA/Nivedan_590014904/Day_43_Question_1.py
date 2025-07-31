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
q = queue()
n = int(input("Enter the number of elements: "))
for i in range(n):
    val = int(input(f"Enter the {i+1} element: "))
    q.enqueue(val)
k = int(input("Enter the value of k:"))
stack = []
for i in range(k):
    stack.append(q.dequeue())
while stack:
    q.enqueue(stack.pop())
for i in range(n-k):
    q.enqueue(q.dequeue())
q.display()
