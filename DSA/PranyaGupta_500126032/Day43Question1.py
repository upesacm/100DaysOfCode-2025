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

class Queue:
    def __init__(self):
        self.queue = []
    def enqueue(self, data):
        self.queue.append(data)
    def dequeue(self):
        if not self.isEmpty():
            return self.queue.pop(0)
        else:
            return None
    def isEmpty(self):
        return len(self.queue)==0
            
    def display(self):
        print(self.queue)
 

class Solution():
    def reverseKElements(self, arr, k):
        q = Queue()
        s= Stack()
        l = len(arr)
        for n in arr:
            q.enqueue(n)
        i=0;    
        while not q.isEmpty() and i<k:
            s.push(q.dequee())
            i+=1;
        while not s.isEmpty():
            q.enqueue(s.pop())
        for i in range(l-k):
            q.enqueue(q.dequeue())
        q.display()    

    
            
        


def main():
    user_input = input("Enter the elements of arr  (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    k = int(input("Enter k: "))
    sol = Solution()
    res = sol.reverseKElements(arr, k)



if __name__ == "__main__":
    main()  