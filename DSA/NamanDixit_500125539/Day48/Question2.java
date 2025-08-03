import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            queue.offer(sc.nextInt());
        }

        Set<Integer> seen = new HashSet<>();
        boolean hasDuplicate = false;

        for (int num : queue) {
            if (!seen.add(num)) {
                hasDuplicate = true;
                break;
            }
        }

        if (hasDuplicate) {
            System.out.println("False");
        } else {
            System.out.println("True");
        }
    }
}
