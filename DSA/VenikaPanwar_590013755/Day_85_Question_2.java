import java.util.*;

public class Day_85_Question_2 {

    // Performs DFS traversal from node 0
    public static void dfs(int vertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]); // undirected
        }
        boolean[] visited = new boolean[vertices];
        dfsHelper(0, graph, visited);
        System.out.println();
    }

    private static void dfsHelper(int node, List<List<Integer>> graph, boolean[] visited) {
        visited[node] = true;
        System.out.print(node + " ");
        for (int nei : graph.get(node)) {
            if (!visited[nei]) dfsHelper(nei, graph, visited);
        }
    }

    public static void main(String[] args) {
        int v1 = 5;
        int[][] e1 = {{0,1},{0,2},{1,3},{2,4}};
        dfs(v1, e1); // Output: 0 1 3 2 4

        int v2 = 4;
        int[][] e2 = {{0,1},{1,2},{2,3}};
        dfs(v2, e2); // Output: 0 1 2 3
    }
}
