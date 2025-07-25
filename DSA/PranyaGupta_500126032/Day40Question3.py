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
    def StackMax(self, stk):
        mainstack = stk
        maxstack = Stack()
        temp = Stack()
        while not mainstack.isEmpty():
            val = mainstack.pop()
            temp.push(val)
        currmax = 0
    
        while not temp.isEmpty():
            val = temp.pop()
            mainstack.push(val)
            currmax = max(currmax, val)
            maxstack.push(currmax)
        return maxstack.peek()    




def main():
    stk = Stack()
    user_input = input("Enter the elements (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    for n in arr:
        stk.push(n)
    sol = Solution()
    res=sol.StackMax(stk)
    print(res)


if __name__ == "__main__":
    main()  