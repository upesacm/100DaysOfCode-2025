import java.util.*;

public class Q2 {
    public static List<String> generateBinaryNumbers(int n) {
        List<String> result = new ArrayList<>();
        Queue<String> queue = new LinkedList<>();

        queue.offer("1");

        for (int i = 0; i < n; i++) {
            String current = queue.poll();
            result.add(current);

            queue.offer(current + "0");
            queue.offer(current + "1");
        }

        return result;
    }

    public static void main(String[] args) {
        int n = 10;
        List<String> binaryList = generateBinaryNumbers(n);
        System.out.println(binaryList);
    }
}
