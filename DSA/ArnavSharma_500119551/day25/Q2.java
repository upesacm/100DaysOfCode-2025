/*2. Intersection Sorted Linked Lists 
A problem that demonstrates merge-like operations on sorted data structures and teaches how 
to find common elements efficiently between two sorted lists. 
Given that two linked lists are sorted in increasing order, create a new linked list 
representing the intersection of the two linked lists. The new linked list should be made 
without changing the original lists. The elements of the linked list are not necessarily 
distinct. This operation is fundamental in data analysis and set operations where you need 
to find common elements between sorted datasets efficiently without modifying the 
original data structures. 
This introduces merge-based intersection and sorted data processing techniques that are 
crucial for database operations and efficient set computations. 
Your task: Find intersection of two sorted linked lists by creating a new list while preserving 
original lists. 
Examples 
Input: 
LinkedList1 = 1->2->3->4->6, LinkedList2 = 2->4->6->8 
Output: 
2->4->6 
Input: 
LinkedList1 = 10->20->40->50, LinkedList2 = 15->40 
Output: 
40  */

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
        Node newNode=new Node(data);
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

    public void intersection(Linked_lt other){
        Node temp1=this.head;
        Node temp2=other.head;

        boolean first=true;

        while(temp1!=null&&temp2!=null){
            if(temp1.data==temp2.data){
                if(!first)System.out.print("->");
                System.out.print(temp1.data);
                temp1=temp1.next;
                temp2=temp2.next;
                first=false;
            }
            else if(temp1.data<temp2.data){
                temp1=temp1.next;
            }
            else{
                temp2=temp2.next;
            }
        }
        if(!first)System.out.println();
    }
}

public class Q2{
    public static void main(String[] args){
        Linked_lt list1=new Linked_lt();
        list1.insert(1);
        list1.insert(2);
        list1.insert(3);
        list1.insert(4);
        list1.insert(6);
        Linked_lt list2=new Linked_lt();
        list2.insert(2);
        list2.insert(4);
        list2.insert(6);
        list2.insert(8);
        list1.intersection(list2); 
    }
}
