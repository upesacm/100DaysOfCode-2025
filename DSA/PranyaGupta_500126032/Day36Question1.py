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
        print(self.stack[-1])
    def isEmpty(self):
        return len(self.stack)==0
            
    def display(self):
        print(self.stack) 

class Solution():
    def reverse(self, s):
        stk = Stack()
        for c in s:
            stk.push(c)
        rev = '' 
        while not stk.isEmpty():
            rev+=stk.pop()
        return rev

def main():
    s = input("Enter the string: ")
    sol = Solution()
    result = sol.reverse(s)
    print(result)

if __name__ == "__main__":
    main()     

