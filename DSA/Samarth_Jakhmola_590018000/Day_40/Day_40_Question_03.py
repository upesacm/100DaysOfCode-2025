class Stack:
    def __init__(self):
        self.stack = []
        self.max_stack = []
        
    def push(self, element):
        self.stack.append(element)
        if not self.max_stack or element >= self.max_stack[-1]:
            self.max_stack.append(element)
        else:
            self.max_stack.append(self.max_stack[-1])

    def pop(self):
        if self.stack:
            self.stack.pop()
            self.max_stack.pop()

    def getMax(self):
        if self.max_stack:
            return self.max_stack[-1]
        else:
            print("The stack is empty.")

try:
    s = Stack()
    while True:
        print("\nChoose an operation : \n 1. Push \n 2. Pop \n 3. Get Maximum Element \n 4. Exit")
        choice = input("Enter your choice (1 - 4):")
        
        if choice == '1':
            val = int(input("Enter the value you want to push : "))
            s.push(val)
        elif choice == '2':
            s.pop()
        elif choice == '3':
            print(s.getMax())
        elif choice == '4':
            break
        else:
            print("Invalid input. Please try with a valid input.")
except:
    print("Invalid input. Please try with a valid input.")
