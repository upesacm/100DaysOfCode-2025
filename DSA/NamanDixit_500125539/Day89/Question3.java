import java.util.*;

public class Question3 {

    private static void dfs(int node, boolean[] visited, ArrayList<ArrayList<Integer>> adj, Stack<Integer> st) {
        visited[node] = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj, st);
            }
        }
        st.push(node);
    }

    private static void dfs2(int node, boolean[] visited, ArrayList<ArrayList<Integer>> reversedAdj) {
        System.out.print(node + " ");
        visited[node] = true;
        for (int neighbor : reversedAdj.get(node)) {
            if (!visited[neighbor]) {
                dfs2(neighbor, visited, reversedAdj);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of vertices (V): ");
        int V = sc.nextInt();

        System.out.print("Enter the number of edges (E): ");
        int E = sc.nextInt();

        // Step 1: Build the original graph
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        System.out.println("Enter the edges (u v):");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
        }

        // Step 2: First DFS pass to fill the stack
        Stack<Integer> st = new Stack<>();
        boolean[] visited = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        // Step 3: Build the reversed graph
        ArrayList<ArrayList<Integer>> reversedAdj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            reversedAdj.add(new ArrayList<>());
        }

        for (int i = 0; i < V; i++) {
            for (int neighbor : adj.get(i)) {
                reversedAdj.get(neighbor).add(i);
            }
        }

        // Step 4: Second DFS pass on the reversed graph
        Arrays.fill(visited, false);
        System.out.println("\nStrongly Connected Components (SCCs):");

        while (!st.isEmpty()) {
            int node = st.pop();
            if (!visited[node]) {
                System.out.print("SCC: ");
                dfs2(node, visited, reversedAdj);
                System.out.println();
            }
        }

        sc.close();
    }
}
