from collections import deque

def compare_queues(q1, q2):
    if len(q1) != len(q2):
        return "No"
    
    temp1 , temp2 = deque() , deque()
    while q1 and q2:
        e1 = q1.popleft()
        e2 = q2.popleft()

        temp1.append(e1)
        temp2.append(e2)

        if e1 != e2:
             while temp1:
                 q1.append(temp1.popleft())
             while temp2:
                 q2.append(temp2.popleft())
             return "No"
    
    while temp1:
        q1.append(temp1.popleft())
    while temp2:
        q2.append(temp2.popleft())
    
    return "Yes"

#example
q1=deque([11,22,33])
q2=deque([11,22,33])
print(compare_queues(q1,q2))