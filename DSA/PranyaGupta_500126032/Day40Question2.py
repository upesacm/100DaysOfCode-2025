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
    def maxRect(self, arr):
        h=0
        w=0
        area=0
        stk = Stack()
        i=0
        while i<len(arr):
            if stk.isEmpty() or arr[i] >= arr[stk.peek()]:
                stk.push(i)
                i+=1
            else:
                h = arr[stk.pop()]
                if stk.isEmpty():
                    w = i
                else:
                    w = i - stk.peek() -1
                area = max(area, w*h)
        while not stk.isEmpty():
            h = arr[stk.pop()]
            if stk.isEmpty():
                w = i
            else:
                w = i - stk.peek() -1   
            area = max(area, w*h)       
        return area            



def main():
    user_input = input("Enter the heights  (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    sol = Solution()
    res=sol.maxRect(arr)
    print(res)


if __name__ == "__main__":
    main()  