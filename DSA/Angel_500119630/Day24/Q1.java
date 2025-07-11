import java.util.Scanner;

public class Q1 {
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
        Node head = createList();
        printList(head);
        head = reverseList(head); // Question1
        printList(head);

    }
}
