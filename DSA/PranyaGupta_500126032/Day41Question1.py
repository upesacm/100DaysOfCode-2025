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

    def lengthofstk(self):
        return len(self.stack)  

class Solution():
    def removeDuplicate(self, stk):
        res = Stack()
        while not stk.isEmpty():
            temp = stk.pop()
            if(temp == res.peek()):
                res.pop()
            else:    
                res.push(temp)
        return res        




def main():
    stk = Stack()
    user_input = input("Enter the string: ")
    arr = list(user_input)
    for n in arr:
        stk.push(n)
    sol = Solution()
    res = sol.removeDuplicate(stk)
    print(''.join(res.stack))


if __name__ == "__main__":
    main()  