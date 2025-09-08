import java.util.*;

public class Day_85_Question_3 {

    // Counts connected components in undirected graph
    public static int countComponents(int vertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        boolean[] visited = new boolean[vertices];
        int count = 0;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                count++;
            }
        }
        return count;
    }

    private static void dfs(int node, List<List<Integer>> graph, boolean[] visited) {
        visited[node] = true;
        for (int nei : graph.get(node)) {
            if (!visited[nei]) dfs(nei, graph, visited);
        }
    }

    public static void main(String[] args) {
        int v1 = 5;
        int[][] e1 = {{0,1},{1,2},{3,4}};
        System.out.println(countComponents(v1, e1)); // Output: 2

        int v2 = 4;
        int[][] e2 = {{0,1},{2,3}};
        System.out.println(countComponents(v2, e2)); // Output: 2
    }
}
