import java.util.*;
public class Day_38_Question_1 {
    static int[] nextGreaterElement(int[] arr){
        Stack<Integer> st = new Stack<>();
        int[] nge = new int[arr.length];
        for(int i=arr.length-1;i>=0;i--){
            while(!st.isEmpty() && st.peek() <= arr[i]) st.pop();
            if(st.isEmpty()) nge[i] = -1;
            else nge[i] = st.peek();
            st.push(arr[i]);
        }
        return nge;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of elemnets in array : ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i =0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int[] nge = nextGreaterElement(arr);
        for(int i =0;i<n;i++){
            System.out.print(nge[i]+" ");
        }
    }
}
