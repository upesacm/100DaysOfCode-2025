
/*
2. Frequency in a Linked List
A problem that demonstrates linked list traversal and counting techniques, teaching how to search and count occurrences of specific elements.

Given a singly linked list and a key, count the number of occurrences of the given key in the linked list. This operation is fundamental in data analysis and frequency counting applications where you need to determine how often specific values appear in sequential data structures. The challenge involves understanding how to traverse the entire list while maintaining an accurate count of matches.

This introduces sequential search algorithms and frequency analysis techniques that are crucial for data processing and statistical analysis of linked data structures.

Your task: Count occurrences of a specific key in a linked list using efficient traversal and counting methods.

Examples
Input:

Linked List: 1->2->1->2->1->3->1, key = 1
Output:

4
Input:

Linked List: 1->2->1->2->1, key = 3
Output:

0
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
    
    public int freqinll(int target){
        if(head==null){
            return 0;
        }
        int count=0;
        Node temp=head;
        while(temp!=null)
          {if(temp.data==target)count++;
        temp=temp.next;}
        return count;
    }
    
}

public class Q2 {
    public static void main(String[] args) {
        ll listt = new ll();
        listt.insert(1);
        listt.insert(1);
        listt.insert(2);
        listt.insert(1);
        listt.insert(2);
        listt.insert(3);
        System.out.println("Frequency of 1: " + listt.freqinll(1)); // 4
        System.out.println("Frequency of 2: " + listt.freqinll(2)); // 2
        System.out.println("Frequency of 3: " + listt.freqinll(3)); // 1
        System.out.println("Frequency of 4: " + listt.freqinll(4)); // 0
    }
}
