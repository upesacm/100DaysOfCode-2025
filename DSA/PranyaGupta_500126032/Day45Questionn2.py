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
    def qsize(self):
        return len(self.queue)
    def isEmpty(self):
        return len(self.queue)==0
    
        
    
 

class Solution():
    def equalQueue(self, q1, q2):
        if q1.qsize() != q2.qsize():
            return False
        for _ in range(q1.qsize()):
            val1 = q1.dequeue()
            val2 = q2.dequeue()
            q1.enqueue(val1)
            q2.enqueue(val2)
            if val1!=val2:
                return False
        return True    
        

def main():
    user_input1 = input("Enter the elements of Queue 1 (with space in between): ")
    arr1 = list(map(int, user_input1.strip().split()))
    q1 = Queue()
    for n in arr1:
        q1.enqueue(n)
    user_input2 = input("Enter the elements of Queue 2(with space in between): ")
    arr2 = list(map(int, user_input2.strip().split()))
    q2 = Queue()
    for n in arr2:
        q2.enqueue(n)
    sol = Solution()
    res = sol.equalQueue(q1,q2)
    print(res)



if __name__ == "__main__":
    main()  