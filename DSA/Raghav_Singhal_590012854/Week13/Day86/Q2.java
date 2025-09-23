import java.util.*;

public class Q2 {
    public static boolean hasCycle(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) graph.get(e[0]).add(e[1]);

        boolean[] visited = new boolean[n];
        boolean[] recStack = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, recStack)) return true;
            }
        }
        return false;
    }

    private static boolean dfs(int node, List<List<Integer>> graph, boolean[] visited, boolean[] recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor] && dfs(neighbor, graph, visited, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true; // found a back edge
            }
        }

        recStack[node] = false; // backtrack
        return false;
    }

    public static void main(String[] args) {
        int n1 = 3;
        int[][] edges1 = {{0,1},{1,2},{2,0}};
        System.out.println(hasCycle(n1, edges1) ? "Yes" : "No"); // Yes

        int n2 = 4;
        int[][] edges2 = {{0,1},{1,2},{2,3}};
        System.out.println(hasCycle(n2, edges2) ? "Yes" : "No"); // No

        int n3 = 4;
        int[][] edges3 = {{0,1},{1,2},{2,0},{2,3}};
        System.out.println(hasCycle(n3, edges3) ? "Yes" : "No"); // Yes
    }
}
