class TwoStacks:
    def __init__(self, size):
        self.size = size
        self.array = [None] * size
        self.top1 = -1
        self.top2 = size

    def push1(self, x):
        if self.top1 + 1 < self.top2:
            self.top1 += 1
            self.array[self.top1] = x
        else:
            print("Stack Overflow in Stack 1.")

    def push2(self, x):
        if self.top1 + 1 < self.top2:
            self.top2 -= 1
            self.array[self.top2] = x
        else:
            print("Stack Overflow in Stack 2.")

    def pop1(self):
        if self.top1 >= 0:
            val = self.array[self.top1]
            self.top1 -= 1
            return val
        else:
            print("Stack Underflow in Stack 1.")
            return None
        
    def pop1(self):
        if self.top2 >= 0:
            val = self.array[self.top2]
            self.top2 -= 1
            return val
        else:
            print("Stack Underflow in Stack 2.")
            return None
        
    def print_stacks(self):
        print(f"Stack1:{self.array[:self.top1 + 1]},Stack2:{self.array[self.top2:]}")

if __name__ == "__main__":
    size = int(input("Enter the size of the array : "))
    ts = TwoStacks(size)

    while True:
            print("\nChoose an operation : \n 1. Push in Stack1 \n 2. Push in Stack2 \n 3. Pop from Stcak1 \n 4. Pop from Stack2 \n 5. " \
            "Print both stacks \n 6. Exit")

            choice = input("Enter your choice (1 - 5): ")
            if choice == '1':
                val = int(input("Enter value to push in Stack1 : "))
                ts.push1(val)
            elif choice == '2':
                val = int(input("Enter value to push in Stack2 : "))
                ts.push2(val)
            elif choice == '3':
                print(f"Popped from Stack1 : {ts.pop1()}")
            elif choice == '4':
                print(f"Popped from Stack2 : {ts.pop2()}")
            elif choice == '5':
                ts.print_stacks()
            elif choice == '6':
                break
            else:
                print("Invalid input. Please try with a valid input.")
