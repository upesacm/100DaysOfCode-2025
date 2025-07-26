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
    def decode(self, s):
        numstk = Stack()
        strstk = Stack()
        nm = 0
        st = ""
        for c in s:
            if c.isdigit():
                nm = 10*nm+int(c)
            elif c == '[':
                numstk.push(nm)
                strstk.push(st)
                st = ""
            elif c==']':
                ch = strstk.pop()
                nm = numstk.pop()
                st= ch+ nm*st
                nm = 0
            else:
                st+=c
        return st            








def main():
    user_input = input("Enter the string: ")
    sol = Solution()
    res = sol.decode(user_input)
    print(res)


if __name__ == "__main__":
    main()  