import java.util.*;

public class Question1 {

    // Function to return minimum cost to connect N ropes
    static int minCost(int a[]) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Insert all elements into the priority queue
        for (int i = 0; i < a.length; i++) {
            pq.add(a[i]);
        }

        int ans = 0;

        // Combine ropes until one remains
        while (pq.size() > 1) {
            int first = pq.poll();
            int second = pq.poll();
            int sum = first + second;
            ans += sum;
            pq.add(sum);
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input
        System.out.print("Enter number of ropes: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter rope lengths:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Output
        int result = minCost(arr);
        System.out.println("Minimum cost to connect ropes: " + result);

        sc.close();
    }
}
