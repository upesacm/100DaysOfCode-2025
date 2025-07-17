import java.util.Scanner;
public class Day_32_Question_2 {
    // Solution 2
    public static int findingNonRepeating(int[] arr){
        int unique = 0;
        for(int i=0;i<arr.length;i++){
            unique^=arr[i];
        }
        return unique;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of elemnets in array : ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i =0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int unique = findingNonRepeating(arr);
        System.out.println(unique);
    }
}
