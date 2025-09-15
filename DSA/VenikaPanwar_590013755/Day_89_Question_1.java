public class Day_89_Question_1 {

    // Kruskal's algorithm for MST
    public static int kruskal(int vertices, int[][] edges) {
        java.util.Arrays.sort(edges, java.util.Comparator.comparingInt(a -> a[2]));
        int[] parent = new int[vertices];
        for (int i = 0; i < vertices; i++) parent[i] = i;
        int cost = 0, count = 0;

        for (int[] e : edges) {
            int u = find(parent, e[0]);
            int v = find(parent, e[1]);
            if (u != v) {
                parent[u] = v;
                cost += e[2];
                count++;
                if (count == vertices - 1) break;
            }
        }
        return cost;
    }

    private static int find(int[] parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    public static void main(String[] args) {
        int v1 = 4;
        int[][] e1 = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
        System.out.println(kruskal(v1, e1)); // Output: 19

        int v2 = 3;
        int[][] e2 = {{0,1,1},{1,2,2},{0,2,3}};
        System.out.println(kruskal(v2, e2)); // Output: 3
    }
}
