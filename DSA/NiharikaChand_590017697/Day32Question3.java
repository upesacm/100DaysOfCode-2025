import java.util.*;
class Day32Question3
{
    public static int findXOR(int arr[]) 
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
        System.out.print("Enter array elements: ");
        for (int i = 0; i < n; i++) 
        {
            arr[i] = sc.nextInt();
        }

        int result = findXOR(arr);
        System.out.println("Output: " + result);
    }
}
