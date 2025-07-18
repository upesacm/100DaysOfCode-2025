
import java.util.*;

public class Question2 {
    public int singleNumber(int arr[]){
        int sing=arr[0];
        for(int i=1; i<arr.length; i++){
            sing=sing^arr[i];
        }
        return sing;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter array elements: ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();

        }
        Question2 obj= new Question2();
        System.out.println(obj.singleNumber(arr));

    }

}
