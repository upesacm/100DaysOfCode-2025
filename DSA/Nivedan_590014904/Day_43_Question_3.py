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
stack = []
word = input("Enter the word: ")
for ch in word:
    q.enqueue(ch)
    stack.append(ch)
while stack:
    if q.dequeue() != stack.pop():
        print("False")
        break
else:
    print("True")
