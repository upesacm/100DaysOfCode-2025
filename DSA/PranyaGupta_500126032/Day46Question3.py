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
    def qsize(self):
        return len(self.queue)
    def printQueue(self):
        print(self.queue)
     
    
 

class Solution():
    def mergeQueue(self, q1, q2):
        q = Queue()
        for i in range(q1.qsize()):
            val = q1.dequeue()
            q.enqueue(val)
            q1.enqueue(val)
        for i in range(q2.qsize()):
            val = q2.dequeue()
            q.enqueue(val)
            q2.enqueue(val)
        q.printQueue()    
            


        

def main():
    user_input1 = input("Enter the elements of Queue1 (with space in between): ")
    arr1 = list(map(int, user_input1.strip().split()))
    q1 = Queue()
    for n in arr1:
        q1.enqueue(n)
    user_input2 = input("Enter the elements of Queue2 (with space in between): ")
    arr2 = list(map(int, user_input2.strip().split()))
    q2 = Queue()
    for n in arr2:
        q2.enqueue(n)
    
    sol = Solution()
    sol.mergeQueue(q1, q2)




if __name__ == "__main__":
    main()  