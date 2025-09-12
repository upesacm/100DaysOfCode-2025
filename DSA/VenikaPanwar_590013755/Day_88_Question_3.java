public class Day_88_Question_3 {

    // Checks if graph is bipartite using BFS coloring
    public static boolean isBipartite(int vertices, int[][] edges) {
        java.util.List<java.util.List<Integer>> graph = new java.util.ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new java.util.ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        int[] color = new int[vertices];
        java.util.Arrays.fill(color, -1);
        for (int i = 0; i < vertices; i++) {
            if (color[i] == -1) {
                java.util.Queue<Integer> queue = new java.util.LinkedList<>();
                queue.offer(i);
                color[i] = 0;
                while (!queue.isEmpty()) {
                    int node = queue.poll();
                    for (int nei : graph.get(node)) {
                        if (color[nei] == -1) {
                            color[nei] = 1 - color[node];
                            queue.offer(nei);
                        } else if (color[nei] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int v1 = 4;
        int[][] e1 = {{0,1},{1,2},{2,3},{3,0}};
        System.out.println(isBipartite(v1, e1) ? "Yes" : "No"); // Output: Yes

        int v2 = 3;
        int[][] e2 = {{0,1},{1,2},{2,0}};
        System.out.println(isBipartite(v2, e2) ? "Yes" : "No"); // Output: No
    }
}
