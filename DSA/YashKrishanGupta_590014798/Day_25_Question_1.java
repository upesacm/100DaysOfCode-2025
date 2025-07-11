import java.util.Scanner;

public class Day_25_Question_1 {
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
    public static boolean isPalindrome(Node head){
        if(head==null) return true;
        Node fast = head;
        Node slow = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        Node firstHalf = head;
        Node secHalf = reverseList(slow.next);

        while(secHalf!=null){
            if(firstHalf.data != secHalf.data) return false;
            firstHalf = firstHalf.next;
            secHalf = secHalf.next;
        }
        return true;
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
            System.out.print(temp.data+"->");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Node head = createList();
        if(isPalindrome(head)) System.out.println("Linked List is palindrome");
        else System.out.println("Linked List is not palindrome");
    }
}
