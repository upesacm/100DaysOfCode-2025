n = int(input())
m = int(input())
graph = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

degrees = [len(graph[i]) for i in range(n)]
odd = sum(1 for d in degrees if d % 2 == 1)

if odd == 0:
    print("Eulerian Circuit Exists")
elif odd == 2:
    print("Eulerian Path Exists")
else:
    print("No Eulerian Path or Circuit Exists")
