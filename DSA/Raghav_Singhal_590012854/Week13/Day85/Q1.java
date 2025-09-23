import java.util.*;

public class Q1 {
    public static List<Integer> bfsTraversal(int vertices, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new ArrayList<>());
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[vertices];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        visited[0] = true;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            result.add(node);
            for (int neighbor : graph.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[][] edges1 = {{0,1},{0,2},{1,3},{2,4}};
        System.out.println(bfsTraversal(5, edges1));
        int[][] edges2 = {{0,1},{1,2},{2,3}};
        System.out.println(bfsTraversal(4, edges2));
    }
}
