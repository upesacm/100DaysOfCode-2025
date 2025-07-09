/*
2. Remove Duplicates from a Sorted Linked List
A problem that demonstrates linked list modification techniques and teaches how to remove duplicate elements while maintaining list integrity.

Given a singly linked list that is already sorted, the task is to remove duplicates (nodes with duplicate values) from the given list if they exist. This operation is fundamental in data cleaning and deduplication applications where you need to eliminate redundant entries while preserving the original order. The challenge involves understanding how to properly link nodes while skipping duplicates and managing memory efficiently.

This introduces linked list modification and duplicate removal techniques that are crucial for data preprocessing and memory-efficient list operations.

Your task: Remove duplicate nodes from a sorted linked list while maintaining proper node connections.

Examples
Input:LinkedList: 2->2->4->5
Output: 2->4->5
Input:
LinkedList: 2->2->2->2->2
Output: 2
 */



 class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}

class linked_lt{
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

    public void rm_duplicates(){
        if(head==null){
            System.out.println("nothijng to return");return;}
        Node temp=head;
        while(temp.next!=null){
            if(temp.data==temp.next.data){
                temp.next=temp.next.next;
            }else{
                temp=temp.next;
            }
        }
        Node temp1=head;
        while (temp1!=temp.next){ 
            System.out.print(temp1.data+" ");
            temp1=temp1.next;
        }

}}


public class Q2 {
    public static void main(String[] args) {
        linked_lt list1=new linked_lt();
        list1.insert(1);
        list1.insert(1);
        list1.insert(1);
        list1.insert(2);
        list1.insert(2);
        list1.insert(3);
        list1.insert(3);
        list1.insert(4);
        list1.rm_duplicates();
    }
}
