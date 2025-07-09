/*
3. Delete Middle of Linked List
A problem that teaches linked list deletion techniques and demonstrates how to remove specific nodes while maintaining list structure.
Given a singly linked list, delete the middle of the linked list. If there are even nodes, then there would be two middle nodes, and we need to delete the second middle element. If the input linked list has a single node, then it should return NULL. This problem is commonly used in memory management and list optimization where you need to remove elements based on position while maintaining list integrity.
This teaches node deletion techniques and position-based removal that are essential for dynamic list management and memory optimization.
Your task: Delete the middle node of a linked list while properly handling edge cases and maintaining list connections.
Examples
Input:
LinkedList: 1->2->3->4->5
Output:
1->2->4->5
Input:
LinkedList: 2->4->6->7->5->1
Output: 2->4->6->5->1
 */



class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}

class linkd_lt{
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

    public void rm_middle(){
        if (head==null||head.next==null) {
            head=null;
            return;
        }
        int count=0;
        Node temp=head;
        while(temp.next!=null){
            count++;
            temp=temp.next;
        }
        int mid=count/2;
        temp=head;
        int i=0;
        while(i<mid){
            if(i==mid-1){
                temp.next=temp.next.next;
            }else{
                temp=temp.next;
            }
            i++;
        }temp=head;
        while(temp.next!=null){
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
    }
}

public class Q3 {
        public static void main(String[] args) {
        linkd_lt list1=new linkd_lt();
        list1.insert(1);
        list1.insert(2);
        list1.insert(3);
        list1.insert(4);
        list1.insert(5);
        list1.insert(6);
        list1.insert(7);
        list1.insert(8);
        list1.rm_middle();
        System.out.println();
        list1.rm_middle();
        System.out.println();
        list1.rm_middle();
        System.out.println();
        list1.rm_middle();  
        System.out.println();
        list1.rm_middle();                
    }
}
