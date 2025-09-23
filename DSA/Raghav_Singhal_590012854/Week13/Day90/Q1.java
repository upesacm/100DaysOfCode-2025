import java.util.*;

class Q1 {
    static boolean hamiltonianUtil(int u, boolean[] vis, int count, List<List<Integer>> adj, int V){
        if(count == V) return true;
        for(int v: adj.get(u)){
            if(!vis[v]){
                vis[v] = true;
                if(hamiltonianUtil(v, vis, count+1, adj, V)) return true;
                vis[v] = false;
            }
        }
        return false;
    }

    static boolean hasHamiltonianPath(int V, int[][] edges){
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0;i<V;i++) adj.add(new ArrayList<>());
        for(int[] e: edges){ adj.get(e[0]).add(e[1]); adj.get(e[1]).add(e[0]); }
        for(int i=0;i<V;i++){
            boolean[] vis = new boolean[V];
            vis[i] = true;
            if(hamiltonianUtil(i, vis, 1, adj, V)) return true;
        }
        return false;
    }

    public static void main(String[] args){
        int V = 4;
        int[][] edges = {{0,1},{1,2},{2,3},{3,0}};
        System.out.println(hasHamiltonianPath(V,edges) ? "Yes" : "No");
    }
}