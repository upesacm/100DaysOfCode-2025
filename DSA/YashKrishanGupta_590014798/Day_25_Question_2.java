import java.util.Scanner;
public class Day_25_Question_2 {
      public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
    }
    // Solution 2
    public static Node intersectionOfLists(Node l1 , Node l2){
          Node head = new Node(0);
          Node temp = head;
          while(l1!=null && l2 != null) {
              if(l1.data == l2.data){
                  temp.next = new Node(l1.data);
                  temp = temp.next;
                  l1 = l1.next;
                  l2 = l2.next;
              }
              else if(l1.data>l2.data) l2 = l2.next;
              else l1 = l1.next;
          }
          return head.next;
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
        System.out.println("Enter sorted Lists");
        Node list1 = createList();
        Node list2 = createList();
        Node head = intersectionOfLists(list1 , list2);
        printList(head);
    }
}
