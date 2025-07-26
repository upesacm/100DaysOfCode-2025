import java.util.*;

public class Q2 {

    public static int[] stock(Stack<Integer> prices) {
        int n = prices.size();
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            int curPrice = prices.get(i);

            while (!st.isEmpty() && prices.get(st.peek()) <= curPrice) {
                st.pop();
            }

            ans[i] = st.isEmpty() ? (i + 1) : (i - st.peek());

            st.push(i);
        }
        return ans;
    }

    public static void main(String[] args) {
        Stack<Integer> prices = new Stack<>();
        prices.push(100);
        prices.push(80);
        prices.push(60);
        prices.push(70);
        prices.push(60);
        prices.push(75);
        prices.push(85);

        int[] spans = stock(prices);
        printArray(spans);
    }

    public static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i + 1 < arr.length) System.out.print(", ");
        }
        System.out.println("]");
    }
}
