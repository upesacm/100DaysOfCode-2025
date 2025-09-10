import java.util.*;

class Solution {
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> bfs = new ArrayList<>();
        boolean[] vis = new boolean[V];
        Queue<Integer> q = new LinkedList<>();

        q.add(0); // Start from vertex 0
        vis[0] = true;

        while (!q.isEmpty()) {
            Integer node = q.poll();
            bfs.add(node);

            // Get all adjacent vertices of the dequeued vertex
            // If a adjacent has not been visited, then mark it visited and enqueue it
            for (Integer it : adj.get(node)) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.add(it);
                }
            }
        }

        return bfs;
    }
}

public class Question1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of vertices: ");
        int V = sc.nextInt();
        
        // Initialize adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        System.out.print("Enter the number of edges: ");
        int E = sc.nextInt();
        
        System.out.println("Enter " + E + " edges (source and destination):");
        for (int i = 0; i < E; i++) {
            System.out.print("Edge " + (i + 1) + " (source destination): ");
            int src = sc.nextInt();
            int dest = sc.nextInt();
            adj.get(src).add(dest); // Add edge
            adj.get(dest).add(src); // For undirected graph
        }

        Solution sol = new Solution();
        ArrayList<Integer> bfs = sol.bfsOfGraph(V, adj);

        System.out.println("BFS Traversal of the graph: " + bfs);
        
        sc.close();
    }
}
