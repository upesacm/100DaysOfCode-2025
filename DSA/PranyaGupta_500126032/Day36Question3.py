class Stack:
    def __init__(self):
        self.stack = []
    def push(self, data):
        self.stack.append(data)
    def pop(self):
        if not self.isEmpty():
            return self.stack.pop()
        else:
            return ''    
    def peek(self):
        if not self.isEmpty():
            return self.stack[-1]
        else:
            return None
    def isEmpty(self):
        return len(self.stack)==0
            
    def display(self):
        print(self.stack)

class Solution():
    def appendAtButtom(self, arr, n):
        stk = Stack()
        for num in arr:
            stk.push(num)
        print("Stack before")    
        stk.display()
        temp = []
        while(not stk.isEmpty()):
            temp.append(stk.pop())
        stk.push(n)
        for t in temp[::-1]:
            stk.push(t)
        print("Stack after: ")
        stk.display();        


def main():
    user_input = input("Enter elements of the array (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    s = int(input("Enter the number to push: "))
    sol = Solution()
    sol.appendAtButtom(arr, s)


if __name__ == "__main__":
    main()     