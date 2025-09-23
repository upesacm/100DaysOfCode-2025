import java.util.*;

class Q3 {
    public static void main(String[] args) {
        int V = 4;
        int[][] edges = {{0,1},{1,2},{2,3},{3,0}};
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0;i<V;i++) adj.add(new ArrayList<>());
        for(int[] e : edges){
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        int[] color = new int[V];
        Arrays.fill(color,-1);
        boolean bipartite = true;
        for(int i=0;i<V;i++){
            if(color[i]==-1 && !dfs(i,1,adj,color)){
                bipartite=false; break;
            }
        }
        System.out.println(bipartite ? "Yes" : "No");
    }

    static boolean dfs(int u, int c, List<List<Integer>> adj, int[] color){
        color[u] = c;
        for(int v : adj.get(u)){
            if(color[v]==-1){
                if(!dfs(v,1-c,adj,color)) return false;
            } else if(color[v]==c) return false;
        }
        return true;
    }
}
