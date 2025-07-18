import java.util.Scanner;
public class Day_32_Question_3 {
    // Solution 3
    public static int xorOfArray(int[] arr){
        int xor = 0;
        for(int i=0;i<arr.length;i++){
            xor^=arr[i];
        }
        return xor;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of elemnets in array : ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i =0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int xor = xorOfArray(arr);
        System.out.println(xor);
    }
}
