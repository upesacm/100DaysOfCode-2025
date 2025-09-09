import java.util.*;

public class Question2 {

    // DFS check for cycle
    private static boolean dfsCheck(int node, ArrayList<ArrayList<Integer>> adj, int[] vis, int[] pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int it : adj.get(node)) {
            if (vis[it] == 0) {
                if (dfsCheck(it, adj, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[it] == 1) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0; // backtrack
        return false;
    }

    // Function to detect cycle in directed graph
    public static boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        int[] vis = new int[V];
        int[] pathVis = new int[V];

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfsCheck(i, adj, vis, pathVis)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input vertices and edges
        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();
        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();

        // Create adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        System.out.println("Enter edges (u v): ");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v); // directed graph
        }

        // Check cycle
        if (isCyclic(V, adj)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        sc.close();
    }
}
