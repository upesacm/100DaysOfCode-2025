import java.util.*;
import java.util.LinkedList;
class Day43Question3
{
    public static boolean checkPalin(Queue<Character> queue) 
    {
        Stack<Character> stack = new Stack<>();
        int size = queue.size();
        for (int i = 0; i < size; i++) 
        {
            char ch = queue.poll();
            stack.push(ch);
            queue.offer(ch); 
        }

        for (int i = 0; i < size; i++) 
        {
            char ch = queue.poll();
            char fromStack = stack.pop();
            if (ch != fromStack) 
            {
                return false;
            }
            queue.offer(ch); 
        }
        return true;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Character> queue = new LinkedList<>();
        System.out.print("Enter the characters (no spaces, e.g. racecar): ");
        String input = sc.nextLine();

        char[] arr = input.toCharArray();
        for (int i = 0; i < arr.length; i++) 
        {
            queue.offer(arr[i]);
        }

        if (checkPalin(queue)) 
        {
            System.out.println("Yes");
        } 
        else 
        {
            System.out.println("No");
        }
    }
}

