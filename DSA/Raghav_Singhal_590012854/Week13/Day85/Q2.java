import java.util.*;

public class Q2 {
    public static void dfsUtil(int node, boolean[] visited, List<List<Integer>> graph, List<Integer> result) {
        visited[node] = true;
        result.add(node);
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited, graph, result);
            }
        }
    }

    public static List<Integer> dfsTraversal(int vertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new ArrayList<>());
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[vertices];
        dfsUtil(0, visited, graph, result);
        return result;
    }

    public static void main(String[] args) {
        int[][] edges1 = {{0,1},{0,2},{1,3},{2,4}};
        System.out.println(dfsTraversal(5, edges1));
        int[][] edges2 = {{0,1},{1,2},{2,3}};
        System.out.println(dfsTraversal(4, edges2));
    }
}
