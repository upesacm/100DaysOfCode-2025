import java.util.*;

public class Question1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of vertices (n):");
        int n = sc.nextInt();

        System.out.println("Enter the number of edges (m):");
        int m = sc.nextInt();

        // Adjacency list to represent the graph
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        System.out.println("Enter the edges (u v):");
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        System.out.println("Enter the source node (src):");
        int src = sc.nextInt();

        int[] dist = shortestPath(adj, n, src);

        System.out.println("Shortest distances from source " + src + " are:");
        for (int i = 0; i < n; i++) {
            System.out.print(dist[i] + " ");
        }
        System.out.println();

        sc.close();
    }

    public static int[] shortestPath(ArrayList<ArrayList<Integer>> adj, int n, int src) {
        int[] dist = new int[n];
        Arrays.fill(dist, -1);

        Queue<Integer> q = new LinkedList<>();

        dist[src] = 0;
        q.add(src);

        while (!q.isEmpty()) {
            int node = q.poll();

            for (int neighbor : adj.get(node)) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.add(neighbor);
                }
            }
        }
        return dist;
    }
}
