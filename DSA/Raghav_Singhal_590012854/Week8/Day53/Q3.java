public class Q3 {
    public static void main(String args[]) {
        int[] arr = {2,1,4,7,3,2,5};
        System.out.println(Mountain(arr));
        System.out.println(Mountain(new int[]{2,2,2}));
    }

    static int Mountain(int[] arr) {
        int count=0,max=0;
        boolean isUp;
        for (int i = 0; i < arr.length-1; i++) {
            isUp=true;
            count=0;
            for (int j = i+1; j < arr.length; j++) {
                if(arr[j-1]<arr[j] && isUp)
                {
                    count++;
                }
                else if(arr[j-1]>arr[j] && isUp)
                {
                    count+=2; // when comparing we get n-1 comparisons and we need to count +1 at some point
                    isUp=false;
                }
                else if(arr[j-1]>arr[j] && !isUp)
                {
                    count++;
                }
                else 
                {
                    if(max<count)
                        max=count;
                    break;
                }
                // count++;
                // if(max<count)
                //         max=count;     
            }
            
        }
        return max;
    }
}