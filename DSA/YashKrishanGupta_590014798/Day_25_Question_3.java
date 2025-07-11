import java.util.Scanner;
public class Day_25_Question_3 {
      public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
        Node(){

        }
    }
    // Solution 3
    public static Node addList(Node l1,Node l2){
          l1 = reverseList(l1);
          l2 = reverseList(l2);
          Node head = new Node(0);
          Node temp = head;
          int carry = 0;
          while(l1!=null || l2!=null || carry > 0){
              int sum = carry;
              if(l1!=null){
                  sum += l1.data;
                  l1 = l1.next;
              }
              if(l2!=null){
                  sum += l2.data;
                  l2 = l2.next;
              }
              carry = sum/10;
              temp.next = new Node(sum%10);
              temp = temp.next;
          }
          head = reverseList(head.next);
          while(head!=null && head.data==0 && head.next!=null){
              head = head.next;
          }
          return head;
    }

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
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        System.out.println("Enter two numbers in form of Linked list");
        Node num1 = createList();
        Node num2 = createList();
        Node head = addList(num1,num2);
        printList(head);
    }
}
