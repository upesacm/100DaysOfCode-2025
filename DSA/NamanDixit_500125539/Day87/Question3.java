// Filename: Question3.java
import java.util.*;

class Question3 {
    static class Edge {
        int u, v, wt;
        Edge(int u, int v, int wt) {
            this.u = u;
            this.v = v;
            this.wt = wt;
        }
    }

    public static int[] bellmanFord(int V, int E, List<Edge> edges, int S) {
        int[] dist = new int[V];
        Arrays.fill(dist, (int)1e8);
        dist[S] = 0;

        // Relax V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (Edge edge : edges) {
                int u = edge.u;
                int v = edge.v;
                int wt = edge.wt;
                if (dist[u] != (int)1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative cycle
        for (Edge edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;
            if (dist[u] != (int)1e8 && dist[u] + wt < dist[v]) {
                return new int[]{-1}; // Negative cycle detected
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input vertices and edges
        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();
        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();

        List<Edge> edges = new ArrayList<>();
        System.out.println("Enter edges in format: u v wt");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int wt = sc.nextInt();
            edges.add(new Edge(u, v, wt));
        }

        System.out.print("Enter source vertex: ");
        int S = sc.nextInt();

        int[] result = bellmanFord(V, E, edges, S);

        if (result.length == 1 && result[0] == -1) {
            System.out.println("Graph contains a negative weight cycle.");
        } else {
            System.out.println("Shortest distances from source " + S + ":");
            for (int i = 0; i < result.length; i++) {
                if (result[i] == (int)1e8) {
                    System.out.print("INF ");
                } else {
                    System.out.print(result[i] + " ");
                }
            }
            System.out.println();
        }

        sc.close();
    }
}
