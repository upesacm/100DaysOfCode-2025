import java.util.*;

class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

public class Question2 {

    public static Node findTail(Node head) {
        Node tail = head;
        while (tail.next != null) {
            tail = tail.next;
        }
        return tail;
    }

    public static List<int[]> findPairs(Node head, int k) {
        List<int[]> ans = new ArrayList<>();
        if (head == null) return ans;

        Node left = head;
        Node right = findTail(head);

        while (left != null && right != null && left != right && left.prev != right) {
            int sum = left.data + right.data;
            if (sum == k) {
                ans.add(new int[]{left.data, right.data});
                left = left.next;
                right = right.prev;
            } else if (sum < k) {
                left = left.next;
            } else {
                right = right.prev;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        Node head = null, tail = null;

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            Node newNode = new Node(val);
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
        }

        System.out.print("Enter target sum: ");
        int k = sc.nextInt();

        List<int[]> pairs = findPairs(head, k);

        if (pairs.isEmpty()) {
            System.out.println("No pairs found.");
        } else {
            System.out.println("Pairs with sum " + k + ":");
            for (int[] pair : pairs) {
                System.out.println("(" + pair[0] + ", " + pair[1] + ")");
            }
        }
    }
}
