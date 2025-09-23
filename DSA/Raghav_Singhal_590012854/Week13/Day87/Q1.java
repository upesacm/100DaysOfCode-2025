import java.util.*;

class Q1 {
    public static void main(String[] args) {
        int V = 6;
        int[][] edges = {{0,1},{0,2},{1,3},{2,4},{4,5}};
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0;i<V;i++) adj.add(new ArrayList<>());
        for(int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        int src = 0;
        int[] dist = new int[V];
        Arrays.fill(dist, -1);
        dist[src] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        while(!q.isEmpty()) {
            int u = q.poll();
            for(int v : adj.get(u)) {
                if(dist[v] == -1) {
                    dist[v] = dist[u]+1;
                    q.add(v);
                }
            }
        }
        System.out.println(Arrays.toString(dist));
    }
}