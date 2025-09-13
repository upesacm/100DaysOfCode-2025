import java.util.*;

public class Question2 {

    static class Pair implements Comparable<Pair> {
        int node;
        int distance;

        public Pair(int distance, int node) {
            this.distance = distance;
            this.node = node;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(this.distance, other.distance);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of vertices (n):");
        int n = sc.nextInt();
        System.out.println("Enter the number of edges (m):");
        int m = sc.nextInt();

        ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        System.out.println("Enter the edges and their weights (u v w):");
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            adj.get(u).add(new Pair(w, v));
            adj.get(v).add(new Pair(w, u)); // For undirected graph
        }

        System.out.println("Enter the source node (src):");
        int src = sc.nextInt();
        System.out.println("Enter the destination node (dest):");
        int dest = sc.nextInt();
        
        System.out.println("\nShortest path from " + src + " to " + dest + ":");
        shortestPath(n, adj, src, dest);

        sc.close();
    }

    public static void shortestPath(int n, ArrayList<ArrayList<Pair>> adj, int src, int dest) {
        int[] dist = new int[n + 1];
        int[] parent = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<Pair> pq = new PriorityQueue<>();

        dist[src] = 0;
        pq.add(new Pair(0, src));

        while (!pq.isEmpty()) {
            int node = pq.poll().node;

            for (Pair neighbor : adj.get(node)) {
                int neighborNode = neighbor.node;
                int weight = neighbor.distance;

                if (dist[node] + weight < dist[neighborNode]) {
                    dist[neighborNode] = dist[node] + weight;
                    parent[neighborNode] = node;
                    pq.add(new Pair(dist[neighborNode], neighborNode));
                }
            }
        }
        
        if (dist[dest] == Integer.MAX_VALUE) {
            System.out.println("No path exists from " + src + " to " + dest);
            return;
        }

        List<Integer> path = new ArrayList<>();
        int currentNode = dest;
        while (currentNode != 0) {
            path.add(currentNode);
            if (currentNode == src) break; // Path found
            currentNode = parent[currentNode];
        }
        
        Collections.reverse(path);
        
        System.out.print("Path: ");
        for (int i = 0; i < path.size(); i++) {
            System.out.print(path.get(i));
            if (i < path.size() - 1) {
                System.out.print(" -> ");
            }
        }
        System.out.println(dist[dest]);
    }
}
