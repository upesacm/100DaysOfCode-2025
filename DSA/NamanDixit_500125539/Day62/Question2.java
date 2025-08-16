
import java.util.*;

public class Question2 {

    public static List<Integer> findClosestElements(int[] arr, int k, int x) {
        // Min-heap based on absolute difference
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1]; // if same difference, smaller element first

                        }return a[0] - b[0]; // smaller difference has higher priority
        });

        // Push elements into heap (skip the target itself if it exists in arr)
        for (int ele : arr) {
            if (ele != x) {
                pq.offer(new int[]{Math.abs(x - ele), ele});
            }
        }

        // Extract k closest elements
        List<Integer> ans = new ArrayList<>();
        while (k-- > 0 && !pq.isEmpty()) {
            ans.add(pq.poll()[1]);
        }

        // Sort them in ascending order (optional depending on problem statement)
        Collections.sort(ans);
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter k: ");
        int k = sc.nextInt();

        System.out.print("Enter x (target): ");
        int x = sc.nextInt();

        // Output
        List<Integer> result = findClosestElements(arr, k, x);
        System.out.println("K closest elements (excluding target): " + result);

        sc.close();
    }
}
