import heapq

def dijkstra(graph, source):
    distance = {node: float('inf') for node in graph}
    distance[source] = 0

    priority_queue = [(0, source)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distance[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            new_distance = current_distance + weight

            if new_distance < distance[neighbor]:
                distance[neighbor] = new_distance
                heapq.heappush(priority_queue, (new_distance, neighbor))

    return distance
