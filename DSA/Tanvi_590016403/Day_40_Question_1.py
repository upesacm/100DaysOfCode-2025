class CelebrityFinder:
    def __init__(self, matrix):
        self.matrix = matrix
        self.n = len(matrix)

    def knows(self, a, b):
        return self.matrix[a][b] == 1

    def find_celebrity(self):
        stack = [i for i in range(self.n)]

        while len(stack) > 1:
            a = stack.pop()
            b = stack.pop()
            if self.knows(a, b):
                stack.append(b)
            else:
                stack.append(a)

        if not stack:
            return -1

        candidate = stack.pop()

        for i in range(self.n):
            if i != candidate:
                if self.knows(candidate, i) or not self.knows(i, candidate):
                    return -1
        return candidate


class HistogramSolver:
    def largest_rectangle_area(self, heights):
        stack = []
        max_area = 0
        heights.append(0)  # Sentinel

        for i, h in enumerate(heights):
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(i)

        return max_area


class MaxStack:
    def __init__(self):
        self.stack = []
        self.max_stack = []

    def push(self, x):
        self.stack.append(x)
        if not self.max_stack or x >= self.max_stack[-1]:
            self.max_stack.append(x)

    def pop(self):
        if not self.stack:
            return None
        val = self.stack.pop()
        if val == self.max_stack[-1]:
            self.max_stack.pop()
        return val

    def getMax(self):
        if not self.max_stack:
            return None
        return self.max_stack[-1]


def main():
    print("Choose a Stack-Based Problem to Solve:")
    print("1. Celebrity Finder")
    print("2. Largest Rectangle in Histogram")
    print("3. MaxStack (getMax in O(1))")
    
    choice = input("Enter your choice (1/2/3): ")

    if choice == "1":
        print("\n--- Celebrity Problem ---")
        n = int(input("Enter number of people: "))
        print("Enter the relationship matrix row by row (0/1 values):")
        matrix = [list(map(int, input().split())) for _ in range(n)]
        cf = CelebrityFinder(matrix)
        result = cf.find_celebrity()
        print(f"Celebrity is: {result}" if result != -1 else "No celebrity found.")

    elif choice == "2":
        print("\n--- Largest Rectangle in Histogram ---")
        heights = list(map(int, input("Enter histogram bar heights (space-separated): ").split()))
        solver = HistogramSolver()
        area = solver.largest_rectangle_area(heights)
        print(f"Largest Rectangle Area: {area}")

    elif choice == "3":
        print("\n--- MaxStack with getMax() ---")
        stack = MaxStack()
        while True:
            print("\nCommands: push <num>, pop, getmax, exit")
            cmd = input("Enter command: ").strip().lower()
            if cmd.startswith("push"):
                _, val = cmd.split()
                stack.push(int(val))
                print(f"Pushed {val}")
            elif cmd == "pop":
                popped = stack.pop()
                print(f"Popped: {popped}" if popped is not None else "Stack is empty.")
            elif cmd == "getmax":
                print(f"Current Max: {stack.getMax()}")
            elif cmd == "exit":
                break
            else:
                print("Invalid command.")
    else:
        print("Invalid choice.")


if __name__ == "__main__":
    main()
