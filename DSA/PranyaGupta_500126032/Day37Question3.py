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
        print(self.stack) 
    def sizeofstk(self):
        return len(self.stack) 
    
class Solution():
    def deletem(self, stk, curr, mid):
        if curr == mid:
            stk.pop()
            return
        temp = stk.pop()
        self.deletem(stk, curr+1, mid)   
        stk.push(temp)

    def deletemid(self, stk):
        n = stk.sizeofstk()
        self.deletem(stk,0,n//2)  
        stk.display()                          


def main():
    stk = Stack()
    user_input = input("Enter elements of the stack (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    for n in arr:
        stk.push(n)
    sol = Solution()
    sol.deletemid(stk)


if __name__ == "__main__":
    main()     

