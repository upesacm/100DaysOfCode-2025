// Filename: Question2.java
import java.util.*;

class Question2 {
    static class Pair {
        int node, weight;
        Pair(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    public static int primsMST(int V, List<List<Pair>> adj) {
        boolean[] vis = new boolean[V];
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.weight));

        pq.offer(new Pair(0, 0)); // start from node 0 with weight 0
        int sum = 0;

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int node = curr.node;
            int wt = curr.weight;

            if (vis[node]) continue;

            // include this node in MST
            vis[node] = true;
            sum += wt;

            for (Pair it : adj.get(node)) {
                if (!vis[it.node]) {
                    pq.offer(new Pair(it.node, it.weight));
                }
            }
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();
        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();

        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        System.out.println("Enter edges in format: u v wt");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int wt = sc.nextInt();
            adj.get(u).add(new Pair(v, wt));
            adj.get(v).add(new Pair(u, wt)); // undirected graph
        }

        int mstWeight = primsMST(V, adj);
        System.out.println(mstWeight);

        sc.close();
    }
}
