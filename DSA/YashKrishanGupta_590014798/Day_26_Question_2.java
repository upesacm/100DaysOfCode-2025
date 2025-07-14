import java.util.Scanner;
public class Day_26_Question_2{
    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
    }
    // Solution 2
    public static Node unionOfLists(Node l1, Node l2) {
        Node merged = mergeLists(l1, l2);
        Node sorted = selectionSort(merged);
        return removeDuplicates(sorted);
    }
  
    public static Node mergeLists(Node l1, Node l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        Node temp = new Node(0);
        Node t = temp;

        while (l1 != null) {
            t.next = new Node(l1.data);
            t = t.next;
            l1 = l1.next;
        }

        while (l2 != null) {
            t.next = new Node(l2.data);
            t = t.next;
            l2 = l2.next;
        }

        return temp.next;
    }

    public static Node selectionSort(Node head) {
        for (Node i = head; i != null; i = i.next) {
            Node min = i;
            for (Node j = i.next; j != null; j = j.next) {
                if (j.data < min.data) {
                    min = j;
                }
            }
            int temp = i.data;
            i.data = min.data;
            min.data = temp;
        }
        return head;
    }

    public static Node removeDuplicates(Node head){
        Node temp = head;
        while(temp!=null && temp.next!=null){
            if(temp.data == temp.next.data) temp.next = temp.next.next;
            else temp = temp.next;
        }
        return head;
    }

    public static Node createList(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of nodes : ");
        int n = sc.nextInt();
        if(n==0) return null;
        System.out.print("Enter " + n + " values: ");
        int data = sc.nextInt();
        Node head = new Node(data);
        Node temp = head;
        for(int i=1;i<n;i++){
            data = sc.nextInt();
            temp.next = new Node(data);
            temp = temp.next;
        }
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
        System.out.println("Enter two Linked list for union");
        Node list1 = createList();
        Node list2 = createList();
        Node head = unionOfLists(list1,list2);
        printList(head);
    }
}
