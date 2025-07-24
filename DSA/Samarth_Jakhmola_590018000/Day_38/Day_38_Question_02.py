class MinStack:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, x):
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    def pop(self):
        if not self.stack:
            return None
        top = self.stack.pop()
        if top == self.min_stack[-1]:
            self.min_stack.pop()
    
    def top(self):
        if not self.stack:
            return None
    
    def get_min(self):
        if not self.min_stack:
            return None
        print(self.min_stack[-1])        

if __name__ == "__main__":
    min_stack = MinStack()
    print("MinStack - Available operations : \n 1. Push \n 2. Pop \n 3. Top \n 4. Get Min \n 5. Exit")
    
    while True:
        choice = input("Enter your choice (1 - 5) : ")
        if choice == '1':
            val = int(input("Enter value to push : "))
            min_stack.push(val)
        elif choice == '2':
            min_stack.pop()
        elif choice == '3':
            min_stack.top()
        elif choice == '4':
            min_stack.get_min()
        elif choice == '5':
            break
        else:
            print("Invalid input. Please try with a valid input.")
