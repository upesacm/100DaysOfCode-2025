public class Day_89_Question_2 {

    // Prim's algorithm for MST
    public static int prim(int vertices, int[][] edges) {
        java.util.List<java.util.List<int[]>> graph = new java.util.ArrayList<>();
        for (int i = 0; i < vertices; i++) graph.add(new java.util.ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(new int[]{e[1], e[2]});
            graph.get(e[1]).add(new int[]{e[0], e[2]});
        }
        boolean[] visited = new boolean[vertices];
        java.util.PriorityQueue<int[]> pq = new java.util.PriorityQueue<>(java.util.Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{0, 0});
        int cost = 0, count = 0;
        while (!pq.isEmpty() && count < vertices) {
            int[] curr = pq.poll();
            int node = curr[0], w = curr[1];
            if (visited[node]) continue;
            visited[node] = true;
            cost += w;
            count++;
            for (int[] nei : graph.get(node)) {
                if (!visited[nei[0]]) pq.offer(new int[]{nei[0], nei[1]});
            }
        }
        return cost;
    }

    public static void main(String[] args) {
        int v1 = 5;
        int[][] e1 = {{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}};
        System.out.println(prim(v1, e1)); // Output: 16

        int v2 = 4;
        int[][] e2 = {{0,1,1},{0,2,2},{2,3,4},{1,3,3}};
        System.out.println(prim(v2, e2)); // Output: 7
    }
}
