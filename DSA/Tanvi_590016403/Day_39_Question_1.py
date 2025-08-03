# ---------- 1. Reverse Stack using Recursion ----------
def insert_at_bottom(stack, item):
    if not stack:
        stack.append(item)
    else:
        top = stack.pop()
        insert_at_bottom(stack, item)
        stack.append(top)

def reverse_stack(stack):
    if stack:
        top = stack.pop()
        reverse_stack(stack)
        insert_at_bottom(stack, top)

# ---------- 2. Stock Span Problem ----------
def calculate_stock_span(prices):
    span = [0] * len(prices)
    stack = []  # stores indices

    for i in range(len(prices)):
        while stack and prices[i] >= prices[stack[-1]]:
            stack.pop()
        span[i] = i + 1 if not stack else i - stack[-1]
        stack.append(i)
    return span

# ---------- 3. Implement 2 Stacks in an Array ----------
class TwoStacks:
    def __init__(self, size):
        self.arr = [None] * size
        self.top1 = -1
        self.top2 = size
        self.size = size

    def push1(self, x):
        if self.top1 + 1 < self.top2:
            self.top1 += 1
            self.arr[self.top1] = x
        else:
            print("Stack1 Overflow")

    def push2(self, x):
        if self.top1 < self.top2 - 1:
            self.top2 -= 1
            self.arr[self.top2] = x
        else:
            print("Stack2 Overflow")

    def pop1(self):
        if self.top1 >= 0:
            val = self.arr[self.top1]
            self.top1 -= 1
            return val
        else:
            print("Stack1 Underflow")
            return None

    def pop2(self):
        if self.top2 < self.size:
            val = self.arr[self.top2]
            self.top2 += 1
            return val
        else:
            print("Stack2 Underflow")
            return None

    def get_stacks(self):
        return self.arr[:self.top1 + 1], self.arr[self.top2:]

# ---------- Menu-Driven Program ----------
def main():
    ts = TwoStacks(10)
    while True:
        print("\n--- Menu ---")
        print("1. Reverse a Stack using Recursion")
        print("2. Solve Stock Span Problem")
        print("3. Use Two Stacks in One Array")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == '1':
            arr = list(map(int, input("Enter stack elements (space-separated): ").split()))
            reverse_stack(arr)
            print("Reversed Stack:", arr)

        elif choice == '2':
            prices = list(map(int, input("Enter stock prices (space-separated): ").split()))
            spans = calculate_stock_span(prices)
            print("Stock Spans:", spans)

        elif choice == '3':
            while True:
                print("\nTwo Stacks Operations:")
                print("a. Push to Stack1")
                print("b. Push to Stack2")
                print("c. Pop from Stack1")
                print("d. Pop from Stack2")
                print("e. Show both stacks")
                print("f. Back to main menu")
                op = input("Enter option (a-f): ").lower()

                if op == 'a':
                    val = int(input("Enter value to push in Stack1: "))
                    ts.push1(val)
                elif op == 'b':
                    val = int(input("Enter value to push in Stack2: "))
                    ts.push2(val)
                elif op == 'c':
                    print("Popped from Stack1:", ts.pop1())
                elif op == 'd':
                    print("Popped from Stack2:", ts.pop2())
                elif op == 'e':
                    s1, s2 = ts.get_stacks()
                    print("Stack1:", s1)
                    print("Stack2:", s2)
                elif op == 'f':
                    break
                else:
                    print("Invalid option!")

        elif choice == '4':
            print("Exiting...")
            break
        else:
            print("Invalid choice!")

if __name__ == "__main__":
    main()
