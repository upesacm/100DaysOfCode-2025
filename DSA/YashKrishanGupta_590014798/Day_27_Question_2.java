import java.util.Scanner;
public class Day_27_Question_2 {
    public static class Node{
        int data;
        Node prev;
        Node next;

        Node(int data){
            this.data=data;
        }
    }
    // Solution 2
    public static Node reverseDlist(Node head){
        Node temp = head;
        Node newhead = null;
        while(temp!=null){
            Node t = temp.prev;
            temp.prev = temp.next;
            temp.next = t;
            newhead = temp;
            temp = temp.prev;
        }
        return newhead;
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
            temp.next.prev = temp;
            temp = temp.next;
        }
        return head;
    }

    public static void printList(Node head){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data+"<-->");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Node head = createList();
        head = reverseDlist(head);
        printList(head);
    }
