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
    def stockSpan(self, arr):
        stk = Stack()
        res = [0]*len(arr)
        for i in range(len(arr)):
            while not stk.isEmpty() and arr[stk.peek()] <= arr[i]:
                stk.pop()
            if stk.isEmpty():
                res[i] = i+1
                
            else:
                res[i] = i- stk.peek()
            stk.push(i)    
        return res;



    


def main():
    user_input = input("Enter the prices (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    sol = Solution()
    print(sol.stockSpan(arr))


if __name__ == "__main__":
    main()     