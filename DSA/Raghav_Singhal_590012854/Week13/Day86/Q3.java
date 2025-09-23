import java.util.*;

public class Q3 {
    private void dfs(int node, boolean[] visited, Stack<Integer> stack, List<List<Integer>> adj) {
        visited[node] = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, stack, adj);
            }
        }
        stack.push(node);
    }

    public List<Integer> topologicalSort(int V, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) adj.get(edge[0]).add(edge[1]);

        boolean[] visited = new boolean[V];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(i, visited, stack, adj);
        }

        List<Integer> topoOrder = new ArrayList<>();
        while (!stack.isEmpty()) topoOrder.add(stack.pop());

        return topoOrder;
    }

    public static void main(String[] args) {
        Q3 obj = new Q3();

        int V1 = 4;
        int[][] edges1 = {{0,1}, {0,2}, {1,3}, {2,3}};
        System.out.println("Topological Sort of Graph 1: " + obj.topologicalSort(V1, edges1));

        int V2 = 6;
        int[][] edges2 = {{5,2}, {5,0}, {4,0}, {4,1}, {2,3}, {3,1}};
        System.out.println("Topological Sort of Graph 2: " + obj.topologicalSort(V2, edges2));
    }
}
