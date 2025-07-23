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
    
class Solution():
    def nextgreatest(self, arr):
        stk = Stack()
        res = [-1]*len(arr)
        for i in range(len(arr)-1, -1, -1):
            while not stk.isEmpty() and stk.peek() <= arr[i]:
                stk.pop()
            if not stk.isEmpty():
                res[i] = stk.peek() 
            stk.push(arr[i])
        return res            


              
def main():
    user_input = input("Enter elements of the arr(with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    sol = Solution()
    res = sol.nextgreatest(arr)
    print(res)


if __name__ == "__main__":
    main()     

