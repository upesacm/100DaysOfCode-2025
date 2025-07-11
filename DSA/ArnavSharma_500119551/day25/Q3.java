/*3. Add Number Linked Lists 
A problem that teaches arithmetic operations on linked list representations and demonstrates 
how to perform addition on numbers stored as linked lists. 
Given the head of two singly linked lists num1 and num2 representing two non-negative 
integers, the task is to return the head of the linked list representing the sum of these two 
numbers. For example, num1 represented by the linked list: 1 -> 9 -> 0, similarly num2 
represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5. 
There can be leading zeros in the input lists, but there should not be any leading zeros in the 
output list. This problem simulates big number arithmetic commonly used in cryptography 
and mathematical computations. 
This teaches digit-by-digit arithmetic and carry propagation techniques that are essential 
for big number operations and mathematical computations in linked structures. 
Your task: Add two numbers represented as linked lists while handling carry propagation 
and leading zero elimination. 
Examples 
Input: 
num1 = 4 -> 5, num2 = 3 -> 4 -> 5 
Output: 
3 -> 9 -> 0 
Input: 
num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7 
Output: 
7 -> 0 */

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

    public static void add(Linked_lt num1,Linked_lt num2){
        Node temp1=num1.head;
        Node temp2=num2.head;
        Linked_lt result=new Linked_lt();
        int carry=0;
        while(temp1!=null||temp2!=null||carry!=0){
            int sum=carry;
            if(temp1!=null){
                sum+=temp1.data;
                temp1=temp1.next;
            }
            if(temp2!=null){
                sum+=temp2.data;
                temp2=temp2.next;
            }
            result.insert(sum%10);
            carry=sum/10;
        }
        Node temp=result.head;
        Node temp3=null,temp4=null;
        while(temp!=null){
            temp4=temp.next;
            temp.next=temp3;
            temp3=temp;
            temp=temp4;
        }
        while(temp3!=null&&temp3.data==0&&temp3.next!=null){
            temp3=temp3.next;
        }
        temp=temp3;
        while(temp!=null){
            System.out.print(temp.data);
            if(temp.next!=null)System.out.print("->");
            temp=temp.next;
        }
    }
}

public class Q3{
    public static void main(String[] args){
        Linked_lt num1=new Linked_lt();
        num1.insert(1);
        num1.insert(9);
        num1.insert(0);
        Linked_lt num2=new Linked_lt();
        num2.insert(2);
        num2.insert(5);
        Linked_lt.add(num1,num2);
        Linked_lt n1=new Linked_lt();
        n1.insert(0);
        n1.insert(0);
        n1.insert(6);
        n1.insert(3);
        Linked_lt n2=new Linked_lt();
        n2.insert(0);
        n2.insert(7);
        Linked_lt.add(n1,n2);
    }
}
