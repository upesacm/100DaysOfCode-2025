import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Question3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        if (!sc.hasNextInt()) {
            System.out.println("Invalid input. Please enter an integer.");
            return;
        }

        int n = sc.nextInt();

        if (n < 0) {
            System.out.println("Number of elements cannot be negative.");
            return;
        }

        if (n == 0) {
            System.out.println(true); // Queue will be empty
            return;
        }

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            if (!sc.hasNextInt()) {
                System.out.println("Invalid element. Please enter integers only.");
                return;
            }
            queue.offer(sc.nextInt());
        }

        System.out.println(queue.isEmpty());
    }
}
