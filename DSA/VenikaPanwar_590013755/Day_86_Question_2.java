import java.util.*;

public class Day_86_Question_2 {

    // Detects cycle in directed graph using DFS and recursion stack
    public static boolean hasDirectedCycle(int vertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) graph.get(e[0]).add(e[1]);
        boolean[] visited = new boolean[vertices];
        boolean[] recStack = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && dfs(i, graph, visited, recStack)) return true;
        }
        return false;
    }

    private static boolean dfs(int node, List<List<Integer>> graph, boolean[] visited, boolean[] recStack) {
        visited[node] = true;
        recStack[node] = true;
        for (int nei : graph.get(node)) {
            if (!visited[nei] && dfs(nei, graph, visited, recStack)) return true;
            else if (recStack[nei]) return true;
        }
        recStack[node] = false;
        return false;
    }

    public static void main(String[] args) {
        int v1 = 3;
        int[][] e1 = {{0,1},{1,2},{2,0}};
        System.out.println(hasDirectedCycle(v1, e1) ? "Yes" : "No"); // Output: Yes

        int v2 = 4;
        int[][] e2 = {{0,1},{1,2},{2,3}};
        System.out.println(hasDirectedCycle(v2, e2) ? "Yes" : "No"); // Output: No
    }
}
