/*
 * 3. Print Linked List
A problem that teaches basic linked list traversal and output formatting, demonstrating fundamental operations for displaying linked list contents.

Given a linked list, print all the elements of the linked list separated by space. This is a fundamental operation in linked list manipulation and serves as the building block for more complex linked list algorithms. Understanding how to properly traverse and display linked list contents is essential for debugging and data visualization in real-world applications.

This teaches basic linked list traversal and output formatting techniques that are essential for linked list debugging and data presentation.

Your task: Traverse and print all elements of a linked list in the correct order with proper spacing.

Examples
Input:

LinkedList: 1 -> 2
Output:

1 2
Input:

Linked List: 49 -> 10 -> 30
Output:

49 10 30
 */

 class Node{
    int data;
    Node next;

    Node(int data){
        this.data=data;
        this.next=null;
    }
}
class ll{
        
    Node head=null;

    public void insert(int data){
        Node newnode= new Node(data);
        if(head==null){
            head=newnode;
            return;
                }
        Node temp=head; 
        while(temp.next!=null)
            temp=temp.next;
        temp.next=newnode;
        }
    
    public void traverse(){
        if(head==null){
            return;
        }
        Node temp=head;
        while(temp!=null)
        {
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
        
    }
    
}


public class Q3 {
    public static void main(String[] var0) {
      ll listt = new ll();
      listt.insert(1);
      listt.insert(1);
      listt.insert(2);
      listt.insert(1);
      listt.insert(2);
      listt.insert(3);
      listt.traverse();
    }
}
