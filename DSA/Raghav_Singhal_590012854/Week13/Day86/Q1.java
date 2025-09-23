import java.util.*;

public class Q1 {
    public static boolean hasCycle(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]); // undirected
        }

        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, graph, visited)) {
                    return true; // cycle found
                }
            }
        }
        return false; // no cycle
    }

    private static boolean dfs(int node, int parent, List<List<Integer>> graph, boolean[] visited) {
        visited[node] = true;

        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, graph, visited)) return true;
            } else if (neighbor != parent) {
                return true; // found a back edge
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int n1 = 3;
        int[][] edges1 = {{0,1},{1,2},{2,0}};
        System.out.println(hasCycle(n1, edges1) ? "Yes" : "No"); // Yes

        int n2 = 3;
        int[][] edges2 = {{0,1},{1,2}};
        System.out.println(hasCycle(n2, edges2) ? "Yes" : "No"); // No

        int n3 = 4;
        int[][] edges3 = {{0,1},{1,2},{2,3},{3,0}};
        System.out.println(hasCycle(n3, edges3) ? "Yes" : "No"); // Yes
    }
}
