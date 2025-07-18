import java.util.Scanner;
public class UniqueElementXOR 
{
    public static void main(String[] args) 
  {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements (all appear twice except one):");
        for (int i = 0; i < n; i++) 
        {
            arr[i] = sc.nextInt();
        }
        int unique = 0;
        for (int num : arr) 
        {
            unique ^= num; 
        }
        System.out.println("The unique non-repeating element is: " + unique);
    }
}
