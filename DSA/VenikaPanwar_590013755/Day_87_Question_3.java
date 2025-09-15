public class Day_87_Question_3 {

    // Bellman-Ford Algorithm: returns shortest distances from source, detects negative cycles
    public static int[] bellmanFord(int vertices, int[][] edges, int source) {
        int[] dist = new int[vertices];
        for (int i = 0; i < vertices; i++) dist[i] = Integer.MAX_VALUE;
        dist[source] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i < vertices; i++) {
            for (int[] e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative cycles
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                throw new RuntimeException("Negative cycle detected");
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int v1 = 5;
        int[][] e1 = {
            {0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},
            {3,2,5},{3,1,1},{4,3,-3}
        };
        int[] res1 = bellmanFord(v1, e1, 0);
        for (int d : res1) System.out.print(d + " "); // Output: 0 -1 2 -2 1
        System.out.println();

        int v2 = 3;
        int[][] e2 = {{0,1,5},{1,2,-2}};
        int[] res2 = bellmanFord(v2, e2, 0);
        for (int d : res2) System.out.print(d + " "); // Output: 0 5 3
        System.out.println();
    }
}
