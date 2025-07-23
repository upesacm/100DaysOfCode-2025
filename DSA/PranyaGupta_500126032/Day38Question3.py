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
    def redundantBrackets(self, exp):
        stk = Stack()   
        for c in exp:
            if c == ")":
                top = stk.pop()
                op = False
                while top != "(":
                    if top in "+-/*":
                        op= True
                    top=stk.pop()  
                if not op:
                    return True
            else:
                stk.push(c)          
        return False
                    

def main():
    exp = input("Enter the expression: ")
    sol = Solution()
    res = sol.redundantBrackets(exp)
    print(res)
    

if __name__ == "__main__":
    main()     

