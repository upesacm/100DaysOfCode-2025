public class Q1 {
    public static void main(String args[]) {
        int [] arr = {1, 4, 2, 10};
        int k = 2;
        System.out.println(klen(arr, k));
    }

    static int klen(int[] arr, int k) {
        if (k< 0)
            return -1;
        int sum, fin = 0;
        for (int i = 0; i <= arr.length - k; i++) {
            sum=0;
            for (int j = i; j < i + k; j++) {
                sum=sum+arr[j];
            }
            if(sum>fin)
            {
                fin=sum;
            }

        }
        return fin;
    }
}
