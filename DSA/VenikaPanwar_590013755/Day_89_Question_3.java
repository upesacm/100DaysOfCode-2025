public class Day_89_Question_3 {

    // Kosaraju's algorithm for SCC count
    public static int kosaraju(int vertices, int[][] edges) {
        java.util.List<java.util.List<Integer>> graph = new java.util.ArrayList<>();
        java.util.List<java.util.List<Integer>> revGraph = new java.util.ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            graph.add(new java.util.ArrayList<>());
            revGraph.add(new java.util.ArrayList<>());
        }
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            revGraph.get(e[1]).add(e[0]);
        }
        boolean[] visited = new boolean[vertices];
        java.util.Stack<Integer> stack = new java.util.Stack<>();
        for (int i = 0; i < vertices; i++)
            if (!visited[i]) dfs1(graph, visited, stack, i);

        java.util.Arrays.fill(visited, false);
        int count = 0;
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!visited[node]) {
                dfs2(revGraph, visited, node);
                count++;
            }
        }
        return count;
    }

    private static void dfs1(java.util.List<java.util.List<Integer>> graph, boolean[] visited, java.util.Stack<Integer> stack, int node) {
        visited[node] = true;
        for (int nei : graph.get(node))
            if (!visited[nei]) dfs1(graph, visited, stack, nei);
        stack.push(node);
    }

    private static void dfs2(java.util.List<java.util.List<Integer>> graph, boolean[] visited, int node) {
        visited[node] = true;
        for (int nei : graph.get(node))
            if (!visited[nei]) dfs2(graph, visited, nei);
    }

    public static void main(String[] args) {
        int v1 = 5;
        int[][] e1 = {{1,0},{0,2},{2,1},{0,3},{3,4}};
        System.out.println(kosaraju(v1, e1)); // Output: 3

        int v2 = 4;
        int[][] e2 = {{0,1},{1,2},{2,3}};
        System.out.println(kosaraju(v2, e2)); // Output: 4
    }
}
