import java.util.Scanner;

public class Day_24_Question_2 {
    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
        Node(){

        }
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

        Scanner sc = new Scanner(System.in);
        System.out.println("For deleting N nodes after M nodes");
        Node head = createList();
        System.out.print("Enter M and N : ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        head = deleteNAfterM(head,m,n);  // Question2
        printList(head);
    }
}
