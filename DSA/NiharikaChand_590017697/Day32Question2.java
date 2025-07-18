import java.util.*;
class Day32Question2
{
    public static int find(int arr[]) 
    {
        int result = 0;

        for (int num : arr) 
        {
            result ^= num;
        }

        return result;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
      
        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element: ");
            arr[i] = sc.nextInt();
        }

        int result = find(arr);
        System.out.println("Output: " + result);
    }
}

