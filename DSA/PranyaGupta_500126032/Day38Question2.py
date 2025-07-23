class Stack:
    def __init__(self):
        self.stack = []
    def push(self, data):
        self.stack.append(data)
    def pop(self):
        if not self.isEmpty():
            return self.stack.pop()
        else:
            return None   
    def peek(self):
        return self.stack[-1]
    
    def isEmpty(self):
        return len(self.stack)==0
            
    def display(self):
        print(self.stack) 
    
class Solution():
    def minElement(self, stk):
        temp = Stack()
        mn = stk.pop()
        while not stk.isEmpty():
            n = stk.pop()
            mn = min(n, mn)
            temp.push(n)
        while not stk.isEmpty():
            temp.push(stk.pop())    
        return mn               



def main():
    stk = Stack()
    user_input = input("Enter elements of the stack (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    for n in arr:
        stk.push(n)
    sol = Solution()
    res = sol.minElement(stk)
    print(res)


if __name__ == "__main__":
    main()     

