import java.util.*;
class Day39Question3
 
{
    int arr[];
    int size;
    int top1, top2;

    public Day39Question3(int n) 
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    public void push1(int val) 
    {
        if (top1 + 1 < top2) 
        {
            top1++;
            arr[top1] = val;
        } 
        else 
        {
            System.out.println("Stack1 overflow");
        }
    }

    public void push2(int val) 
    {
        if (top1 + 1 < top2) 
        {
            top2--;
            arr[top2] = val;
        } 
        else 
        {
            System.out.println("Stack2 overflow");
        }
    }

    public int pop1() 
    {
        if (top1 >= 0) 
        {
            return arr[top1--];
        } 
        else 
        {
            System.out.println("Stack1 underflow");
            return -1;
        }
    }

    public int pop2() 
    {
        if (top2 < size) 
        {
            return arr[top2++];
        } 
        else 
        {
            System.out.println("Stack2 underflow");
            return -1;
        }
    }

    public void printStack1() 
    {
        System.out.print("Stack1: [");
        for (int i = 0; i <= top1; i++) 
        {
            System.out.print(arr[i]);
            if (i != top1) System.out.print(", ");
        }
        System.out.println("]");
    }

    public void printStack2() 
    {
        System.out.print("Stack2: [");
        for (int i = size - 1; i >= top2; i--) 
        {
            System.out.print(arr[i]);
            if (i != top2) System.out.print(", ");
        }
        System.out.println("]");
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day39Question3 ob = new Day39Question3(10);  

        System.out.println("Enter size of Stack1:");
        int n1 = sc.nextInt();
        for (int i = 0; i < n1; i++) 
        {
            System.out.print("Enter element for Stack1: ");
            int val = sc.nextInt();
            ob.push1(val);
        }

        System.out.println("Enter size of Stack2:");
        int n2 = sc.nextInt();
        for (int i = 0; i < n2; i++) 
        {
            System.out.print("Enter element for Stack2: ");
            int val = sc.nextInt();
            ob.push2(val);
        }

        ob.printStack1();  
        ob.printStack2();
    }
}

