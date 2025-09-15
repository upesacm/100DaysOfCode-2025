public class Day_90_Question_2 {

    // Determines if Eulerian Path or Circuit exists
    public static String eulerianType(int vertices, int[][] edges) {
        int[] degree = new int[vertices];
        for (int[] e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
        }
        int odd = 0;
        for (int d : degree) if (d % 2 != 0) odd++;
        if (odd == 0) return "Eulerian Circuit Exists";
        if (odd == 2) return "Eulerian Path Exists";
        return "No Eulerian Path or Circuit";
    }

    public static void main(String[] args) {
        int v1 = 4;
        int[][] e1 = {{0,1},{1,2},{2,0},{0,3}};
        System.out.println(eulerianType(v1, e1)); // Output: Eulerian Path Exists

        int v2 = 3;
        int[][] e2 = {{0,1},{1,2},{2,0}};
        System.out.println(eulerianType(v2, e2)); // Output: Eulerian Circuit Exists
    }
}
