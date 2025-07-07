public class Day_22_Question_1_2_3{
    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
    }

    public static Node middleOfList(Node head){
        Node fast = head;
        Node slow = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public static int frequencyInList(Node head,int key){
        int count = 0;
        Node temp = head;
        while(temp != null){
            if(temp.data == key){
                count++;
            }
            temp = temp.next;
        }
        return count;
    }

    public static void printList(Node head){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        Node head = new Node(3);
        head.next = new Node(2);
        head.next.next = new Node(1);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(1);
        head.next.next.next.next.next = new Node(5);

        System.out.println(middleOfList(head).data);
        System.out.println(frequencyInList(head,1));
        printList(head);


    }
}
