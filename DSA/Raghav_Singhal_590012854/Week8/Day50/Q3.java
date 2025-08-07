
public class Q3 {
    public static void main(String args[]) {
        int[] arr = { 1, 4, 45, 6, 0, 19 };
        int x = 51;
        System.out.println(shortA(arr, x));
    }

    static int shortA(int[] arr, int x) {
        if(x<0) return -1;
        int sum, fin = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            sum=0;
            for (int j = i; j < arr.length; j++) {
                if(sum>x)
                {
                    if((j-i)<fin)
                        fin=j-i;
                    sum=0;
                    break;
                }
                else
                    sum=sum+arr[j];
            }
        }
        return fin;
    }
}
