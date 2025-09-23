import java.util.*;

public class Q3 {
    public static int countComponents(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]); // undirected
        }

        boolean[] visited = new boolean[n];
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                components++;
            }
        }
        return components;
    }

    private static void dfs(int node, List<List<Integer>> graph, boolean[] visited) {
        visited[node] = true;
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    public static void main(String[] args) {
        int n1 = 5;
        int[][] edges1 = {{0,1},{1,2},{3,4}};
        System.out.println(countComponents(n1, edges1)); // Output: 2

        int n2 = 4;
        int[][] edges2 = {{0,1},{2,3}};
        System.out.println(countComponents(n2, edges2)); // Output: 2

        int n3 = 5;
        int[][] edges3 = {};
        System.out.println(countComponents(n3, edges3)); // Output: 5 (all isolated nodes)
    }
}
