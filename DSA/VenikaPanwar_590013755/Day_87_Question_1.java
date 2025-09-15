public class Day_87_Question_1 {

    // BFS-based shortest path from source to all nodes
    public static int[] shortestPath(int vertices, int[][] edges, int source) {
        java.util.List<java.util.List<Integer>> graph = new java.util.ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new java.util.ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        int[] dist = new int[vertices];
        java.util.Arrays.fill(dist, -1);
        java.util.Queue<Integer> queue = new java.util.LinkedList<>();
        dist[source] = 0;
        queue.offer(source);
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int nei : graph.get(node)) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    queue.offer(nei);
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        int v1 = 6;
        int[][] e1 = {{0,1},{0,2},{1,3},{2,4},{4,5}};
        int[] res1 = shortestPath(v1, e1, 0);
        for (int d : res1) System.out.print(d + " "); // Output: 0 1 1 2 2 3
        System.out.println();

        int v2 = 4;
        int[][] e2 = {{0,1},{1,2},{2,3}};
        int[] res2 = shortestPath(v2, e2, 0);
        for (int d : res2) System.out.print(d + " "); // Output: 0 1 2 3
        System.out.println();
    }
}
