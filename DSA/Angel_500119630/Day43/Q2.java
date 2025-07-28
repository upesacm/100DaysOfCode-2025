import java.util.*;
public class Q2 {
    public static void main(String[] args) {
        int n = 5;
        List<String> result = generateBinary(n);
        System.out.println(result);
    }

    public static List<String> generateBinary(int n) {
        List<String> binaryNumbers = new ArrayList<>();
        Queue<String> queue = new LinkedList<>();
        queue.offer("1");
        for (int i = 0; i < n; i++) {
            String current = queue.poll();
            binaryNumbers.add(current);
            queue.offer(current + "0");
            queue.offer(current + "1");
        }
        return binaryNumbers;
    }
}
