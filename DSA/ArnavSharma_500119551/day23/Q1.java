/* 1. Kth from End of Linked List
A problem that introduces advanced linked list traversal techniques and teaches how to find elements from the end efficiently using the two-pointer approach.

Given the head of a linked list and the number k, your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1. This problem appears frequently in interviews and real-world applications like implementing undo operations, recent history tracking, or buffer management systems. You can solve this by first counting nodes and then traversing again, but try to think of more efficient approaches using the two-pointer technique that requires only one pass.

This teaches two-pointer traversal and reverse indexing techniques that are essential for efficient linked list processing and single-pass algorithms.

Your task: Find the kth node from the end of a linked list using efficient single-pass traversal techniques.

Examples
Input:

LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output:

8
Input:

LinkedList: 10->5->100->5, k = 5
Output:

-1
 */

 class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
 }

 class linked_l{
    Node head=null;

    public void insert(int data){
        Node newNode= new Node(data);
        if(head==null){
            head=newNode;
            return;
        }
        Node temp=head;
        while(temp.next!=null){
            temp=temp.next;
    }
    temp.next=newNode;}

    public int kth_from_ll(int k){
        if(head==null||k<0){
            return -1;
        }
        Node temp=head;
        int count=0;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        if(k>count){
            return -1;
        }
        Node temp1=head;
        int i=0;
        while(i<count-k){
            i++;
            temp1=temp1.next;
        }
        return temp1.data;
    }


}

public class Q1{
    public static void main(String[] args) {
        linked_l list1=new linked_l();
        list1.insert(1);
        list1.insert(2);
        list1.insert(3);
        list1.insert(4);
        list1.insert(5);
        list1.insert(6);
        System.out.println("kth item 2 "+list1.kth_from_ll(2));
        System.out.println("kth item 4 "+list1.kth_from_ll(4));
        System.out.println("kth item 10 "+list1.kth_from_ll(10));
    }
}