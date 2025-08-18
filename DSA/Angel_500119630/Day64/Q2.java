import java.util.*;
public class Q2 {
    static class Item {
        int w, v;
        Item(int w, int v) { this.w = w; this.v = v; }
    }
    public static void main(String[] args) {
        int[] w = {10,20,30}, v = {60,100,120};
        int cap = 50, n = w.length;
        Item[] a = new Item[n];
        for (int i = 0; i < n; i++) a[i] = new Item(w[i], v[i]);
        Arrays.sort(a, (x,y) -> Double.compare((double)y.v/y.w,(double)x.v/x.w));
        double res = 0;
        for (Item it : a) {
            if (cap >= it.w) { res += it.v; cap -= it.w; }
            else { res += (double)it.v * cap / it.w; break; }
        }
        System.out.println(res);
    }
}
