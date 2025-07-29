import java.util.*;

public class Question2 {

    // Function to generate binary numbers from 1 to N
    public static List<String> generateBinaryNumbers(int N) {
        List<String> ans = new ArrayList<>();
        Queue<String> q = new LinkedList<>();

        q.offer("1");

        for (int i = 0; i < N; i++) {
            String x = q.poll();
            ans.add(x);
            q.offer(x + "0");
            q.offer(x + "1");
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter value of N: ");
        int N = sc.nextInt();

        List<String> binaryNumbers = generateBinaryNumbers(N);
        for (String bin : binaryNumbers) {
            System.out.print(bin + " ");
        }

        sc.close();
    }
}
