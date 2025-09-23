import java.util.*;

class Q1 {
    static class Edge implements Comparable<Edge>{
        int u,v,wt;
        Edge(int u,int v,int wt){this.u=u;this.v=v;this.wt=wt;}
        public int compareTo(Edge e){ return this.wt - e.wt;}
    }

    static int find(int[] parent,int x){
        if(parent[x]!=x) parent[x]=find(parent,parent[x]);
        return parent[x];
    }

    static void union(int[] parent,int[] rank,int x,int y){
        int xr=find(parent,x), yr=find(parent,y);
        if(xr==yr) return;
        if(rank[xr]<rank[yr]) parent[xr]=yr;
        else if(rank[xr]>rank[yr]) parent[yr]=xr;
        else { parent[yr]=xr; rank[xr]++; }
    }

    public static void main(String[] args){
        int V=4;
        Edge[] edges = {new Edge(0,1,10), new Edge(0,2,6), new Edge(0,3,5), new Edge(1,3,15), new Edge(2,3,4)};
        Arrays.sort(edges);
        int[] parent=new int[V]; int[] rank=new int[V];
        for(int i=0;i<V;i++){ parent[i]=i; rank[i]=0; }
        int mst=0;
        for(Edge e:edges){
            if(find(parent,e.u)!=find(parent,e.v)){
                mst+=e.wt;
                union(parent,rank,e.u,e.v);
            }
        }
        System.out.println(mst);
    }
}
