import java.util.*;

class Q2 {
    static class Pair{ int v,w; Pair(int v,int w){this.v=v;this.w=w;} }
    public static void main(String[] args){
        int V=5;
        List<List<Pair>> adj=new ArrayList<>();
        for(int i=0;i<V;i++) adj.add(new ArrayList<>());
        adj.get(0).add(new Pair(1,2)); adj.get(1).add(new Pair(0,2));
        adj.get(0).add(new Pair(3,6)); adj.get(3).add(new Pair(0,6));
        adj.get(1).add(new Pair(2,3)); adj.get(2).add(new Pair(1,3));
        adj.get(1).add(new Pair(3,8)); adj.get(3).add(new Pair(1,8));
        adj.get(1).add(new Pair(4,5)); adj.get(4).add(new Pair(1,5));
        adj.get(2).add(new Pair(4,7)); adj.get(4).add(new Pair(2,7));
        adj.get(3).add(new Pair(4,9)); adj.get(4).add(new Pair(3,9));

        boolean[] visited=new boolean[V];
        PriorityQueue<Pair> pq=new PriorityQueue<>((a,b)->a.w-b.w);
        pq.add(new Pair(0,0));
        int mst=0;
        while(!pq.isEmpty()){
            Pair cur=pq.poll();
            if(visited[cur.v]) continue;
            visited[cur.v]=true;
            mst+=cur.w;
            for(Pair p:adj.get(cur.v)) if(!visited[p.v]) pq.add(new Pair(p.v,p.w));
        }
        System.out.println(mst);
    }
}
