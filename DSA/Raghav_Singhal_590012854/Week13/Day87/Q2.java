import java.util.*;

class Q2 {
    public static void main(String[] args) {
        int V = 5;
        int[][] edges = {{0,1,2},{0,2,4},{1,2,1},{2,3,7},{1,4,3}};
        List<List<int[]>> adj = new ArrayList<>();
        for(int i=0;i<V;i++) adj.add(new ArrayList<>());
        for(int[] e : edges) adj.get(e[0]).add(new int[]{e[1], e[2]});
        int src = 0;
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.add(new int[]{0, src});
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0], u = curr[1];
            if(d > dist[u]) continue;
            for(int[] e : adj.get(u)) {
                int v = e[0], w = e[1];
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.add(new int[]{dist[v], v});
                }
            }
        }
        System.out.println(Arrays.toString(dist));
    }
}