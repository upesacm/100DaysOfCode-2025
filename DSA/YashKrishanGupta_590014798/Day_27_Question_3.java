import java.util.Scanner;
public class Day_27_Question_3 {
        public static class Node{
        int data;
        Node prev;
        Node next;

        Node(int data){
            this.data=data;
        }
    }
    // Solution 3
    public static Node deleteEveryKthNode(Node head,int k){
        if (head == null || k <= 0) return head;
        if(k==1) return null;
        Node temp = head;
        int count = 1;
        while (temp != null) {
            if (count % k == 0) {
                if (temp.prev != null) temp.prev.next = temp.next;
                if (temp.next != null) temp.next.prev = temp.prev;
                if (temp == head) head = temp.next;
            }
            temp = temp.next;
            count++;
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
        System.out.print("Enter k : ");
        int k = sc.nextInt();
        head = deleteEveryKthNode(head,3);
        printList(head);
    }
}
