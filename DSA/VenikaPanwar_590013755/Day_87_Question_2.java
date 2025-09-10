import java.util.*;

public class Day_87_Question_2 {

    // Dijkstra's algorithm for shortest path in weighted graph
    public static int[] dijkstra(int vertices, int[][] edges, int source) {
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) graph.get(e[0]).add(new int[]{e[1], e[2]});
        int[] dist = new int[vertices];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(java.util.Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{source, 0});
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int node = curr[0], d = curr[1];
            if (d > dist[node]) continue;
            for (int[] nei : graph.get(node)) {
                int next = nei[0], weight = nei[1];
                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.offer(new int[]{next, dist[next]});
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        int v1 = 5;
        int[][] e1 = {{0,1,2},{0,2,4},{1,2,1},{2,3,7},{1,4,3}};
        int[] res1 = dijkstra(v1, e1, 0);
        for (int d : res1) System.out.print(d + " "); // Output: 0 2 3 10 5
        System.out.println();

        int v2 = 3;
        int[][] e2 = {{0,1,5},{1,2,2}};
        int[] res2 = dijkstra(v2, e2, 0);
        for (int d : res2) System.out.print(d + " "); // Output: 0 5 7
        System.out.println();
    }
}
