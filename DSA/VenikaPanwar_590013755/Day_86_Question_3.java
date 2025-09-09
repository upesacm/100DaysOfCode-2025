import java.util.*;

public class Day_86_Question_3 {

    // Topological Sort (DFS) for DAG
    public static List<Integer> topoSort(int vertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) graph.get(e[0]).add(e[1]);
        boolean[] visited = new boolean[vertices];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) dfs(i, graph, visited, stack);
        }
        List<Integer> result = new ArrayList<>();
        while (!stack.isEmpty()) result.add(stack.pop());
        return result;
    }

    private static void dfs(int node, List<List<Integer>> graph, boolean[] visited, Stack<Integer> stack) {
        visited[node] = true;
        for (int nei : graph.get(node)) {
            if (!visited[nei]) dfs(nei, graph, visited, stack);
        }
        stack.push(node);
    }

    public static void main(String[] args) {
        int v1 = 4;
        int[][] e1 = {{0,1},{0,2},{1,3},{2,3}};
        System.out.println(topoSort(v1, e1)); // Output: [0, 2, 1, 3] or [0, 1, 2, 3]

        int v2 = 6;
        int[][] e2 = {{5,2},{5,0},{4,0},{4,1},{2,3},{3,1}};
        System.out.println(topoSort(v2, e2)); // Output: [4, 5, 0, 2, 3, 1] (one valid order)
    }
}
