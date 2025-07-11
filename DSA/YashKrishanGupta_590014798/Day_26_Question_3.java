import java.util.Scanner;
public class Day_26_Question_3 {
    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
    }
    // Solution 3
    public static Node sort012(Node head){
        if(head == null || head.next == null) return head;
        Node temp = head;
        Node temp0 = new Node(-1);
        Node temp1 = new Node(-1);
        Node temp2 = new Node(-1);
        Node zero = temp0 , one = temp1 , two = temp2;
        while(temp!=null){
            if(temp.data==0){
                zero.next = temp;
                zero = zero.next;
            }
            else if(temp.data==1){
                one.next = temp;
                one = one.next;
            }
            else {
                two.next = temp;
                two = two.next;
            }
            temp = temp.next;
        }
        if(temp1.next==null) zero.next = temp2.next;
        else zero.next = temp1.next;
        one.next = temp2.next;
        two.next = null;
        return temp0.next;
    }
;
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
        System.out.println("Enter 0,1,2 in linked list only");
        Node head = createList();
        head = sort012(head);
        printList(head);
    }
}
