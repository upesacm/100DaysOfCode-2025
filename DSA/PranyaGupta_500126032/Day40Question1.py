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
    def celebrityProblem(self, n, mat):
        stk = Stack()
        for i in range(n):
            stk.push(i)
        while stk.lengthofstk()>1:
            a = stk.pop() 
            b = stk.pop()
            if mat[a][b] == 1:
                stk.push(b)
            else:
                stk.push(a)
        if stk.isEmpty():
            return -1
        c = stk.pop()
        for i in range(1, n):
            if i!=c:
                if mat[c][i] ==1 or mat[i][c] !=1:
                    return -1
        return c                           


def main():
    mat = []
    n = int(input("Enter n: "))
    for i in range(n):
        user_input = input(f"Enter row {i+1} (with space in between): ")
        arr = list(map(int, user_input.strip().split()))
        mat.append(arr)
    sol = Solution()
    res=sol.celebrityProblem(n, mat)
    print(res)


if __name__ == "__main__":
    main()  