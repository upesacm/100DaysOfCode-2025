
public class Q2 {
    static class node{
        int val;
        node next;
        node(int val)
        {
            this.val=val;
        }
    }
    public static void main(String[] args) {
        node head1=new node(9);
        head1.next=new node(6);
        head1.next.next=new node(4);
        head1.next.next.next=new node(2);
        head1.next.next.next.next=new node(3);
        head1.next.next.next.next.next=new node(8);

        node head2=new node(1);
        head2.next=new node(2);
        head2.next.next=new node(8);
        head2.next.next.next=new node(6);
        head2.next.next.next.next=new node(2);
        
        node newHead=union(head1,head2);
        printList(newHead);
    }
    public static node union(node head1,node head2)
    {
        node newhead=new node(-1);

        int[] tempArr = new int[1000];
        int i = 0;

        while (head1 != null) {
            tempArr[i++] = head1.val;
            head1 = head1.next;
        }
        while (head2 != null) {
            tempArr[i++] = head2.val;
            head2 = head2.next;
        }

        for (int j = 0; j < i - 1; j++) {
            for (int k = 0; k < i - j - 1; k++) {
                if (tempArr[k] > tempArr[k + 1]) {
                    int temp = tempArr[k];
                    tempArr[k] = tempArr[k + 1];
                    tempArr[k + 1] = temp;
                }
            }
        }
        node tail = newhead;

        for (int j = 0; j < i; j++) {
            if (j == 0 || tempArr[j] != tempArr[j - 1]) {
                tail.next = new node(tempArr[j]);
                tail = tail.next;
            }
        }

        return newhead.next;
    }

    public static void printList(node node) 
    {
        while (node != null) 
        {
            System.out.print(node.val+" -> ");
            node = node.next;
        }
        System.out.println("null");
    }
}
