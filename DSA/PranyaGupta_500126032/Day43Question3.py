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
    def palindromequeue(self, q):
        lst = q.queue
        if lst[::-1]==lst:
            return "Yes"
        else:
            return "No"    

def main():
    s= input("Enter the string (with space in between): ")
    arr = list(s)
    q = Queue()
    for c in s:
        q.enqueue(c)
    sol = Solution()
    res = sol.palindromequeue(q)
    print(res)



if __name__ == "__main__":
    main()  