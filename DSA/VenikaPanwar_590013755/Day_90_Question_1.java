public class Day_90_Question_1 {

    // Checks if Hamiltonian Path exists using backtracking
    public static boolean hasHamiltonianPath(int vertices, int[][] edges) {
        java.util.List<java.util.List<Integer>> graph = new java.util.ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new java.util.ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        boolean[] visited = new boolean[vertices];
        for (int start = 0; start < vertices; start++) {
            if (dfs(graph, visited, start, 1)) return true;
        }
        return false;
    }

    private static boolean dfs(java.util.List<java.util.List<Integer>> graph, boolean[] visited, int node, int count) {
        visited[node] = true;
        if (count == visited.length) return true;
        for (int nei : graph.get(node)) {
            if (!visited[nei]) {
                if (dfs(graph, visited, nei, count + 1)) return true;
            }
        }
        visited[node] = false;
        return false;
    }

    public static void main(String[] args) {
        int v1 = 4;
        int[][] e1 = {{0,1},{1,2},{2,3},{3,0}};
        System.out.println(hasHamiltonianPath(v1, e1) ? "Yes" : "No"); // Output: Yes

        int v2 = 3;
        int[][] e2 = {{0,1},{1,2}};
        System.out.println(hasHamiltonianPath(v2, e2) ? "Yes" : "No"); // Output: Yes
    }
}