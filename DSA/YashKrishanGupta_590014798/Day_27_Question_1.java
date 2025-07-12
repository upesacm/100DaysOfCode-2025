import java.util.Scanner;
public class Day_27_Question_1{
    public static class Node{
        int data;
        Node prev;
        Node next;

        Node(int data){
            this.data=data;
        }
    }
    // Solution 1
    public static Node deleteNode(Node head,int key){
        if (head == null) return null;

        if(head.data==key){
            Node t = head.next;
            if (t != null) t.prev = null;
            return t;
        }

        Node temp = head;
        while(temp!=null){
            if (temp.data == key) {
                temp.prev.next = temp.next;
                if (temp.next != null) temp.next.prev = temp.prev;
                break;
            }
            temp = temp.next;
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
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the data of Node to be deleted :");
        int key = sc.nextInt();
        head = deleteNode(head,key);
        printList(head);
    }
}
