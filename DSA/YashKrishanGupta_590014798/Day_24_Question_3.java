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
        
        Scanner sc = new Scanner(System.in);
        System.out.println("For deleting Xth node");
        Node head = createList();
        System.out.print("Enter X : ");
        int x = sc.nextInt();
        head = deleteXNode(head,x);  // Question3
        printList(head);

    }
}
