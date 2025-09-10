import java.util.*;

public class Day_86_Question_1 {

    // Detects cycle in undirected graph using DFS with parent tracking
    public static boolean hasCycle(int vertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        boolean[] visited = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && dfs(i, -1, graph, visited)) return true;
        }
        return false;
    }

    private static boolean dfs(int node, int parent, List<List<Integer>> graph, boolean[] visited) {
        visited[node] = true;
        for (int nei : graph.get(node)) {
            if (!visited[nei]) {
                if (dfs(nei, node, graph, visited)) return true;
            } else if (nei != parent) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int v1 = 3;
        int[][] e1 = {{0,1},{1,2},{2,0}};
        System.out.println(hasCycle(v1, e1) ? "Yes" : "No"); // Output: Yes

        int v2 = 3;
        int[][] e2 = {{0,1},{1,2}};
        System.out.println(hasCycle(v2, e2) ? "Yes" : "No"); // Output: No
    }
}
