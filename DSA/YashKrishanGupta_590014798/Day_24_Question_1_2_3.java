import java.util.Scanner;

public class Day_24_Question_1_2_3 {
    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
        Node(){

        }
    }
    // Solution 1
    public static Node reverseList(Node head){
        Node before = null;
        Node curr = head;
        while(curr!=null){
            Node after = curr.next;
            curr.next = before;
            before = curr;
            curr = after;
        }
        return before;
    }

    //Solution 2
    public static Node deleteNAfterM(Node head, int m , int n){
        if (head == null || m < 0 || n < 0) return head;
        Node curr = head;
        for(int i=1;i<m && curr!=null;i++){
            curr = curr.next;
        }
        if(curr==null) return head;
        Node temp = curr.next;
        for(int i=0;i<n && temp!=null;i++){
            temp = temp.next;
        }
        curr.next = temp;
        return head;
    }

    //Solution-3
    public static Node deleteXNode(Node head, int x){
        if (head == null || x <= 0) return head;
        Node temp = head;
        if(x==1) return head.next;
        int i = 1;
        while(i<x-1 && temp!=null){
            temp = temp.next;
            i++;
        }
        if(temp==null || temp.next == null) return head;
        temp.next = temp.next.next;
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
            System.out.print(temp.data+"->");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        System.out.println("For reversing list");
        Node head1 = createList();
        printList(head1);
        head1 = reverseList(head1); // Question1
        printList(head1);

        Scanner sc = new Scanner(System.in);

        System.out.println("For deleting N nodes after M nodes");
        Node head2 = createList();
        System.out.print("Enter M and N : ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        head2 = deleteNAfterM(head2,m,n);  // Question2
        printList(head2);

        System.out.println("For deleting Xth node");
        Node head3 = createList();
        System.out.print("Enter X : ");
        int x = sc.nextInt();
        head3 = deleteXNode(head3,x);  // Question3
        printList(head3);

    }
}
