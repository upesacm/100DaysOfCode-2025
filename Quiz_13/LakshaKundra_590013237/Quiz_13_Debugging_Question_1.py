#answer 1
#The missing optimization is the “visited set check
#Typically, Dijkstra’s adds a condition like:
#if current_dist > distances[current_node]:
    #continue
#This avoids re-processing nodes with stale distances

#answer 2
#It still works correctly because every time a shorter distance is found, it updates distances[neighbor] and pushes it back into the heap.
#Even if outdated (longer) paths are processed later, the check if new_dist < distances[neighbor] prevents overwriting shorter paths.
#Therefore, correctness is preserved.
#But it is not optimal because unnecessary nodes are processed multiple times.

#answer 3
#It returns the correct shortest distances:
#{0: 0, 1: 3, 2: 1, 3: 4}
#However, it might push the same node multiple times into the priority queue, making the time complexity worse.

#correct code
import heapq

def dijkstra(graph, start):
    distances = {}
    for node in graph:
        distances[node] = float('inf')
    distances[start] = 0

    pq = [(0, start)]

    while pq:
        current_dist, current_node = heapq.heappop(pq)
        if current_dist > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            new_dist = current_dist + weight
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))

    return distances

graph = {
    0: [(1, 4), (2, 1)],
    1: [(3, 1)],
    2: [(1, 2), (3, 5)],
    3: []
}

result = dijkstra(graph, 0)
print(f"Shortest distances: {result}")
