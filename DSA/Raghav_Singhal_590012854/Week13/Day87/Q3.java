import java.util.*;

class Q3 {
    public static void main(String[] args) {
        int V = 5;
        int[][] edges = {{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}};
        int src = 0;
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        for(int i=1;i<=V-1;i++) {
            for(int[] e : edges) {
                int u=e[0], v=e[1], w=e[2];
                if(dist[u]!=Integer.MAX_VALUE && dist[u]+w<dist[v]) dist[v]=dist[u]+w;
            }
        }
        System.out.println(Arrays.toString(dist));
    }
}