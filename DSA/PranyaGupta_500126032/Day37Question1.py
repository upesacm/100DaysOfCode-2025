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
        return self.stack[-1]
    
    def isEmpty(self):
        return len(self.stack)==0
            
    def display(self):
        print(self.stack[::-1]) 

class Solution():
    def sort(self, stk):
        temp = Stack()
        while(not stk.isEmpty()):
            ele = stk.pop()
            while not temp.isEmpty() and temp.peek() > ele:
                stk.push(temp.pop())
            temp.push(ele)
        while not temp.isEmpty():
            stk.push(temp.pop())
        stk.display()            


def main():
    stk = Stack()
    user_input = input("Enter elements of the stack (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    for n in arr:
        stk.push(n)
    sol = Solution()
    sol.sort(stk)


if __name__ == "__main__":
    main()     

