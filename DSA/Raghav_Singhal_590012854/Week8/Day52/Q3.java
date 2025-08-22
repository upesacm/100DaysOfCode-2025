

public class Q3 {
    public static void main(String args[]) {
        int[] arr = {0,1,0,2,1,0,1,3,2,1,2,1};
        int[] arr1 = {4,2,0,3,2,5};
        System.out.println(trapWater(arr));
        System.out.println(trapWater(arr1));
    }

    static int trapWater(int[] arr) {
        int cur,count=0,max=0;
        for (int i = 0; i < arr.length-1; i++) {
            cur=arr[i];
            for (int j = i+1; j < arr.length; j++) {
                if(arrayMax(arr, j)<arr[j-1])
                    cur=arrayMax(arr, j);
                if(arr[j]>=cur)
                {
                    max+=count;
                    count=0;
                    i=j-1;
                    break;
                }
                count=count+cur-arr[j];
            }

        }
        return max;
    }
    static int arrayMax(int arr[] ,int j)
    {
        int max = arr[0];  
        for (int i = j; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];  
            }
        }
        return max;
    }
}