import java.util.*;
class Day38Question1 
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element:");
            arr[i] = sc.nextInt();
        }

        int result[]= new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = n - 1; i >= 0; i--) 
        {
            while (!st.isEmpty() && st.peek() <= arr[i]) 
            {
                st.pop();
            }

            if (st.isEmpty()) 
            {
                result[i] = -1;
            } 
            else 
            {
                result[i] = st.peek();
            }

            st.push(arr[i]);
        }

        System.out.println("Output: ");
        for (int i = 0; i < n; i++) 
        {
            System.out.print(result[i] + " ");
        }
    }
}

