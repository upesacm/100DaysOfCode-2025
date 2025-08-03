import java.util.*;
public class ArrayXOR 
{
    public static int findXOR(int[] arr) 
  {
        int xor = 0;
        for (int num : arr) 
        {
            xor ^= num;
        }
        return xor;
    }
    public static void main(String[] args) 
  {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int result = findXOR(arr);
        System.out.println("XOR of all elements in the array is: " + result);
    }
}
