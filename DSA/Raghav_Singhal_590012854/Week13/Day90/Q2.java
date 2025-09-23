import java.util.*;

class Q2 {
    static String eulerianStatus(int V, int[][] edges){
        int[] degree = new int[V];
        for(int[] e: edges){ degree[e[0]]++; degree[e[1]]++; }
        int odd = 0;
        for(int d: degree) if(d%2!=0) odd++;
        if(odd==0) return "Eulerian Circuit Exists";
        else if(odd==2) return "Eulerian Path Exists";
        else return "No Eulerian Path or Circuit";
    }

    public static void main(String[] args){
        int V = 4;
        int[][] edges = {{0,1},{1,2},{2,0},{0,3}};
        System.out.println(eulerianStatus(V,edges));
    }
}