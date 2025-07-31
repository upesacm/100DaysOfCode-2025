import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue1 = new LinkedList<>();
        Queue<Integer> queue2 = new LinkedList<>();

        System.out.print("Enter number of elements in Queue 1: ");
        int n1 = sc.nextInt();
        System.out.println("Enter elements of Queue 1:");
        for (int i = 0; i < n1; i++) {
            queue1.offer(sc.nextInt());
        }

        System.out.print("Enter number of elements in Queue 2: ");
        int n2 = sc.nextInt();
        System.out.println("Enter elements of Queue 2:");
        for (int i = 0; i < n2; i++) {
            queue2.offer(sc.nextInt());
        }

        boolean isEqual = true;
        if (queue1.size() != queue2.size()) {
            isEqual = false;
        } else {
            Queue<Integer> temp1 = new LinkedList<>();
            Queue<Integer> temp2 = new LinkedList<>();
            while (!queue1.isEmpty()) {
                int a = queue1.poll();
                int b = queue2.poll();
                if (a != b) {
                    isEqual = false;
                }
                temp1.offer(a);
                temp2.offer(b);
            }
            while (!temp1.isEmpty()) {
                queue1.offer(temp1.poll());
                queue2.offer(temp2.poll());
            }
        }

        System.out.println(isEqual);
    }
}
