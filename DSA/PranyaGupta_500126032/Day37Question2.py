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
    def postfix(self, exp):
        stk = Stack()     
        for c in exp:  
            if c.isdigit():
                stk.push(int(c))
            elif c in "+-*/":
                n1 = stk.pop()
                n2 = stk.pop()
                if c == "+":
                    res = n1+n2
                elif c == "-":
                    res = n2-n1
                elif c == "/":
                    res = n2/n1
                elif c == "*":
                    res = n1*n2
                stk.push(res)        
        return stk.pop()       
                    




def main():
    exp = input("Enter the expression: ")
    sol = Solution()
    res = sol.postfix(exp)
    print(res)



if __name__ == "__main__":
    main()     

