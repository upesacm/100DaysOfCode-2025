2. Queue Merge Operation Bug
Buggy line(s):
if q1:
    result.append(q1.popleft())
if q2:
    result.append(q2.popleft())
2.Why it's incorrect:
This does not alternate elements strictly. It appends from both queues in the same iteration when both are non-empty.
