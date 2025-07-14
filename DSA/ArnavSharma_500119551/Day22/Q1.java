
import java.awt.HeadlessException;
import java.lang.management.ThreadInfo;

/*
*1. Middle of a Linked List
A problem that introduces linked list traversal techniques and teaches how to find the middle element efficiently using the two-pointer approach.

Given the head of a linked list, the task is to find the middle node. For example, the middle of 1->2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4. This problem appears frequently in interviews and real-world applications like implementing efficient search algorithms or dividing linked lists for processing. You can solve this by first counting nodes and then traversing again, but try to think of more efficient approaches using the two-pointer technique.

This teaches two-pointer traversal and optimal linked list navigation techniques that are essential for efficient list processing and divide-and-conquer algorithms.

Your task: Find the middle node of a linked list using efficient traversal techniques without multiple passes.

Examples
Input:

Linked list: 1->2->3->4->5
Output:

3
Input:

Linked list: 2->4->6->7->5->1
Output:

7
 */

 class Node{
    int data;
    Node next;
    
    Node(int data){
    this.data=data;
    this.next=null;
    }
 }

class LinkedListt{
    Node head;
    public void insert(int data){
    Node newnode=new Node(data);
    if(head==null){
    head=newnode;  
    return;
    }

    Node current =head;
    while(current.next!=null){
        current=current.next;
    }
    current.next=newnode;}
    public int middle_element_index(){
        Node temp= head;
        int count=0;
        while(temp!=null){
            temp=temp.next;
            count++;
        }
        return (int) Math.ceil(count / 2.0);
    }
}
public class Q1{
    public static void main(String[] args) {
        LinkedListt list=new LinkedListt();
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(40);
        list.insert(50);
        System.out.println((int)list.middle_element_index());
    }
}