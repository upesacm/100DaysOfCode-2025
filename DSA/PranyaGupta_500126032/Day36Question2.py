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
    def balancedParanthesis(self, s):
        stk = Stack()
        p = {')': '(', ']': '[', '}': '{'}
        for c in s:
            if c in '([{':
                stk.push(c)
            elif c in '})]':
                if stk.isEmpty() or stk.peek()  != p[c]:
                    return "Not Balanced"
                stk.pop()
        if stk.isEmpty():
            return "Balanced"
        else:
            return "Not Balanced{}"             

def main():
    s = input("Enter the parenthesis: ")
    sol = Solution()
    result = sol.balancedParanthesis(s)
    print(result)

if __name__ == "__main__":
    main()     