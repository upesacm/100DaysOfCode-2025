public class Q3 {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        Node head = createList(new int[]{1, 2, 2, 1, 2, 0, 2, 2});
        head = sortList(head);
        printList(head);  
    }

    public static Node sortList(Node head) {
        int[] count = new int[3];
        Node temp = head;

        while (temp != null) {
            count[temp.data]++;
            temp = temp.next;
        }

        temp = head;
        int i = 0;
        while (temp != null) {
            if (count[i] == 0) i++;
            else {
                temp.data = i;
                count[i]--;
                temp = temp.next;
            }
        }

        return head;
    }

    public static Node createList(int[] arr) {
        Node head = new Node(arr[0]), temp = head;
        for (int i = 1; i < arr.length; i++) {
            temp.next = new Node(arr[i]);
            temp = temp.next;
        }
        return head;
    }

    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }
}
