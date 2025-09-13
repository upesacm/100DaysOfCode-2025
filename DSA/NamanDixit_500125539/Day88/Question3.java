import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Solution {
    // BFS approach to check if the graph is bipartite
    private boolean checkBipartiteBFS(int startNode, ArrayList<ArrayList<Integer>> adj, int[] color) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startNode);
        color[startNode] = 0; // Start with color 0

        while (!queue.isEmpty()) {
            int u = queue.poll();

            for (int v : adj.get(u)) {
                // If the adjacent node is not yet colored, color it with the opposite color
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    queue.add(v);
                }
                // If the adjacent node has the same color, the graph is not bipartite
                else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Main method to determine if the graph is bipartite
    public boolean isBipartite(int V, ArrayList<ArrayList<Integer>> adj) {
        int[] color = new int[V];
        Arrays.fill(color, -1); // Initialize colors with -1 (uncolored)

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!checkBipartiteBFS(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
}

public class Question3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution solution = new Solution();

        System.out.println("Enter the number of vertices (V):");
        int V = scanner.nextInt();

        System.out.println("Enter the number of edges (E):");
        int E = scanner.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        System.out.println("Enter the edges (u v):");
        for (int i = 0; i < E; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u); // Since it's an undirected graph
        }

        boolean result = solution.isBipartite(V, adj);

        if (result) {
            System.out.println("The graph is bipartite.");
        } else {
            System.out.println("The graph is not bipartite.");
        }

        scanner.close();
    }
}
