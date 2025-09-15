// Filename: Question1.java
import java.util.*;

class Question1 {
    static class Edge implements Comparable<Edge> {
        int u, v, wt;
        Edge(int u, int v, int wt) {
            this.u = u;
            this.v = v;
            this.wt = wt;
        }
        public int compareTo(Edge other) {
            return this.wt - other.wt; // sort by weight
        }
    }

    static class DisjointSet {
        int[] parent, size;

        DisjointSet(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]); // path compression
        }

        boolean union(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return false; // already connected

            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            return true;
        }
    }

    public static int kruskalMST(int V, List<Edge> edges) {
        Collections.sort(edges); // sort edges by weight
        DisjointSet ds = new DisjointSet(V);
        int mstWeight = 0;
        List<Edge> mstEdges = new ArrayList<>();

        for (Edge e : edges) {
            if (ds.union(e.u, e.v)) {
                mstWeight += e.wt;
                mstEdges.add(e);
            }
        }

        // Print selected edges
        System.out.println("Selected edges in MST:");
        for (Edge e : mstEdges) {
            System.out.println(e.u + " - " + e.v + " (" + e.wt + ")");
        }

        return mstWeight;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();
        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();

        List<Edge> edges = new ArrayList<>();
        System.out.println("Enter edges in format: u v wt");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int wt = sc.nextInt();
            edges.add(new Edge(u, v, wt));
        }

        int mstWeight = kruskalMST(V, edges);
        System.out.println(mstWeight);

        sc.close();
    }
}
