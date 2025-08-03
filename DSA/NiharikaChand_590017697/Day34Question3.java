import java.util.*;
class Day34Question3
{
    public static String isPalin(int n) 
    {
        int msb = -1;
        for (int i = 31; i >= 0; i--) 
        {
            if (((n >> i) & 1) == 1) 
            {
                msb = i;
                break;
            }
        }

        int left = msb; 
        int right = 0;  

        while (left > right) 
        {
            int leftBit = (n >> left) & 1;
            int rightBit = (n >> right) & 1;

            if (leftBit != rightBit) 
            {
                return "No";
            }

            left--;
            right++;
        }
        return "Yes";
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        String result = isPalin(n);
        System.out.println("Output: " + result);
    }
}
