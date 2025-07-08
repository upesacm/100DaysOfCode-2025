public class Day_23_Question_1_2_3{

    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
        Node(){

        }
    }

    public static int kFromEnd(Node head,int k){
        Node fast = head;
        Node slow = head;
        int i = 0;
        while (i < k) {
            if (fast == null) return -1;
            fast = fast.next;
            i++;
        }
            while(fast!=null){
            slow = slow.next;
            fast = fast.next;
        }

        return slow.data;
    }

    public static void removeDuplicates(Node head){
        Node temp = head;
        while(temp!=null && temp.next!=null){
            if(temp.data == temp.next.data) temp.next = temp.next.next;
            else temp = temp.next;
        }
    }

    public static Node deleteMiddle(Node head){
        if(head == null || head.next == null) return null;
        Node fast = head;
        Node slow = head;
        Node prev = null;
        while(fast != null && fast.next != null){
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        prev.next = slow.next;
        return head;
    }

    public static void printList(Node head){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node head = new Node(1);
        head.next = new Node(1);
        head.next.next = new Node(2);
        head.next.next.next = new Node(3);
        head.next.next.next.next = new Node(4);
        head.next.next.next.next.next = new Node(4);
        head.next.next.next.next.next.next = new Node(6);
        head.next.next.next.next.next.next.next = new Node(6);
        head.next.next.next.next.next.next.next.next = new Node(8);
        head.next.next.next.next.next.next.next.next.next = new Node(9);

        System.out.println(kFromEnd(head,2));
        printList(head);
        removeDuplicates(head);
        printList(head);
        head = deleteMiddle(head);
        printList(head);



    }
