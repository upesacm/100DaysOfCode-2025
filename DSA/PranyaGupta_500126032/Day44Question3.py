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
    
 

class Solution():
    def isEmpty(self, q):
        return len(q.queue)==0

            

    

def main():
    user_input = input("Enter the elements of arr  (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    q = Queue()
    for n in arr:
        q.enqueue(n)
    sol = Solution()
    res = sol.isEmpty(q)
    print(res)



if __name__ == "__main__":
    main()  