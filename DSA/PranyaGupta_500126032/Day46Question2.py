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
     
    
 

class Solution():
    def oddevencount(self, q):
        oddc = 0
        evenc = 0
        for i in range(q.qsize()):
            val = q.dequeue()
            if val%2==0:
                evenc+=1
            else:
                oddc+=1    
            q.enqueue(val)  
        return f"Even: {evenc}  Odd: {oddc}"    


        

def main():
    user_input = input("Enter the elements of Queue (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    q = Queue()
    for n in arr:
        q.enqueue(n)
    sol = Solution()
    res = sol.oddevencount(q)
    print(res)



if __name__ == "__main__":
    main()  