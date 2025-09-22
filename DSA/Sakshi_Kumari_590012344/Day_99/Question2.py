class Stack:
    def __init__(self):
        self.items = []

    def push(self, value):
        if not self.items:
            self.items.append((value, value))
        else:
            current_max = max(value, self.items[-1][1])
            self.items.append((value, current_max))

    def pop(self):
        if self.items:
            return self.items.pop()[0]
        return None

    def get_max(self):
        if self.items:
            return self.items[-1][1]
        return None

    def is_empty(self):
        return len(self.items) == 0


def sliding_window_max(arr, k):
    inStack = Stack()
    outStack = Stack()
    result = []

    def get_window_max():
        max1 = inStack.get_max()
        max2 = outStack.get_max()
        if max1 is None:
            return max2
        if max2 is None:
            return max1
        return max(max1, max2)

    for i in range(len(arr)):
        inStack.push(arr[i])

        if i >= k - 1:
            result.append(get_window_max())

            if outStack.is_empty():
                while not inStack.is_empty():
                    val = inStack.pop()
                    if outStack.is_empty():
                        outStack.push(val)
                    else:
                        current_max = max(val, outStack.get_max())
                        outStack.items.append((val, current_max))

            outStack.pop()

    return result


n = int(input("Enter number of elements in array: "))
arr = []
for i in range(n):
    arr.append(int(input("Enter element: ")))

k = int(input("Enter window size: "))

ans = sliding_window_max(arr, k)
print("Maximum in each window:", ans)
