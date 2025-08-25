import java.util.*;

public class Question2 {

    // Function to return minimum cost of connecting ropes
    public static int minCost(int[] arr) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Insert all elements into priority queue
        for (int i = 0; i < arr.length; i++) {
            pq.add(arr[i]);
        }

        int ans = 0;

        // Continue until only one rope remains
        while (pq.size() > 1) {
            int first = pq.poll();   // smallest rope
            int second = pq.poll();  // second smallest rope

            int sum = first + second;
            ans += sum;

            pq.add(sum);  // push combined rope back into queue
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of ropes: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the lengths of ropes:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int result = minCost(arr);
        System.out.println(result);

        sc.close();
    }
}
