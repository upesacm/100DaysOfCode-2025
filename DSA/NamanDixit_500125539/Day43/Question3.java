import java.util.*;

public class Question3 {

    // Node class
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    // Function to check if the linked list is a palindrome
    static boolean isPalindrome(Node head) {
        Node tempNode = head;
        Stack<Integer> stack = new Stack<>();

        // Push all elements to the stack
        while (tempNode != null) {
            stack.push(tempNode.data);
            tempNode = tempNode.next;
        }

        // Compare with original list
        while (head != null) {
            if (head.data != stack.pop()) {
                return false;
            }
            head = head.next;
        }

        return true;
    }

    // Main method: take inputs from user
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node head = null, tail = null;

        System.out.print("Enter the number of nodes: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            Node newNode = new Node(val);

            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        boolean result = isPalindrome(head);
        System.out.println(result);

        sc.close();
    }
}
