import java.util.Scanner;
public class Day_26_Question_1 {
    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
    }
    // Solution 1
    public static Node swapKthNodesFromEnds(Node head,int k){
        if(head == null || head.next == null || k<=0) return head;
        Node start = head;
        Node end = head;
        Node prev1 = null;
        Node prev2 = null;
        int i = 1;
        while(i<k && start!=null){
            prev1 = start;
            start = start.next;
            i++;
        }
        if(start==null) return head;
        Node temp = start;
        while(temp.next!=null){
            prev2 = end;
            temp = temp.next;
            end = end.next;
            i++;
        }
        if(start == end ) return head;

        if(prev1!=null) prev1.next = end;
        else head = end;

        if(prev2!=null) prev2.next = start;
        else head = start;

        temp = end.next;
        end.next = start.next;
        start.next = temp;

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
        Node head = createList();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter K :");
        int k = sc.nextInt();
        head = swapKthNodesFromEnds(head,k);
        printList(head);
    }
}
