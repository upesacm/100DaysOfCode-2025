import java.util.*;

public class Day_43_Question_2 {
    public static List<String> generateBinary(int n) {
        List<String> result = new ArrayList<>();
        Queue<String> queue = new LinkedList<>();
        queue.add("1");

        for (int i = 0; i < n; i++) {
            String curr = queue.remove();
            result.add(curr);
            queue.add(curr + "0");
            queue.add(curr + "1");
        }

        return result;
    }

    public static void main(String[] args) {
        int n = 5;
        List<String> binaries = generateBinary(n);
        System.out.println("Binary numbers from 1 to " + n + ": " + binaries);
    }
}
