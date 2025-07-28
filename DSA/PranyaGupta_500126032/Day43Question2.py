class Queue:
    def __init__(self):
        self.queue = []
    def enque(self, data):
        self.queue.append(data)
    def deque(self):
        if not self.isEmpty():
            return self.queue.pop(0)
        else:
            return None
    def isEmpty(self):
        return len(self.queue)==0
            
    def display(self):
        print(self.queue)
 

class Solution():
    def binaryNumbers(self, n):
        q = Queue() 
        res = []
        q.enque("1")
        for i in range(n):
            num = q.deque()
            res.append(str(num))
            q.enque(str(num)+"1")
            q.enque(str(num)+"0")

        return res
    

def main():
    n = int(input("Enter n: "))
    sol = Solution()
    res = sol.binaryNumbers(n)
    print(res)



if __name__ == "__main__":
    main()  