import java.util.*;

class Q3 {
    static void dfs(int u,List<List<Integer>> adj,boolean[] vis,Stack<Integer> st){
        vis[u]=true;
        for(int v:adj.get(u)) if(!vis[v]) dfs(v,adj,vis,st);
        st.push(u);
    }

    static void dfs2(int u,List<List<Integer>> radj,boolean[] vis){
        vis[u]=true;
        for(int v:radj.get(u)) if(!vis[v]) dfs2(v,radj,vis);
    }

    public static void main(String[] args){
        int V=5;
        int[][] edges={{1,0},{0,2},{2,1},{0,3},{3,4}};
        List<List<Integer>> adj=new ArrayList<>();
        List<List<Integer>> radj=new ArrayList<>();
        for(int i=0;i<V;i++){ adj.add(new ArrayList<>()); radj.add(new ArrayList<>()); }
        for(int[] e:edges){ adj.get(e[0]).add(e[1]); radj.get(e[1]).add(e[0]); }
        boolean[] vis=new boolean[V];
        Stack<Integer> st=new Stack<>();
        for(int i=0;i<V;i++) if(!vis[i]) dfs(i,adj,vis,st);
        Arrays.fill(vis,false);
        int scc=0;
        while(!st.isEmpty()){
            int u=st.pop();
            if(!vis[u]){ dfs2(u,radj,vis); scc++; }
        }
        System.out.println(scc);
    }
}
