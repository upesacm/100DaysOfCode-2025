/* 1. Palindrome Linked List
A problem that introduces advanced linked list analysis techniques and teaches how to check symmetry in sequential data structures efficiently.

Given a head singly linked list of positive integers, the task is to check if the given linked list is palindrome or not. A palindrome reads the same forwards and backwards. This problem appears frequently in interviews and real-world applications like data validation, symmetry detection in sequences, or implementing verification algorithms. You can solve this by converting to an array first, but try to think of more efficient approaches using techniques like reversing half the list or using two pointers with recursion.

This teaches symmetry detection and two-pointer validation techniques that are essential for pattern recognition and efficient data structure analysis.

Your task: Check if a linked list is a palindrome using efficient techniques without extra space or with minimal space complexity.

Examples
Input:

head: 1 -> 2 -> 1 -> 1 -> 2 -> 1
Output:

true
Input:

head: 1 -> 2 -> 3 -> 4
Output:

false*/


class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}

class Linked_lt{
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
        temp.next=newNode;
    }

    public boolean palindrome() {
    Node temp=head;
    int count=0;
    while(temp!=null) {
        count++;
        temp=temp.next;
    }

    int mid=count/2;
    temp=head;
    for (int i=0;i<mid;i++) {
        temp=temp.next;
    }
    Node temp1=null;
    Node temp2=null;
    while (temp!=null) {
        temp2=temp.next;
        temp.next=temp1;
        temp1=temp;
        temp=temp2;
    }
    temp=head;
    while (temp1!=null) {
        if (temp.data!=temp1.data) {
            return false;
        }
        temp=temp.next;
        temp1=temp1.next;
    }

    return true;
}}



public class Q1 {
    public static void main(String[] args) {
        Linked_lt list = new Linked_lt();
        list.insert(1);
        list.insert(2);
        list.insert(1);
        list.insert(1);
        list.insert(2);
        list.insert(1);

        System.out.println("Palindrome: " + list.palindrome()); // Output: true
    }
}
