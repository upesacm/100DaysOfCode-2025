import java.util.*;
public class Q2 {
    public static void main(String args[])
    {
        int Array1[] = {1, 3, 5}, Array2[] = {2, 4, 6};
        System.out.println(mergeSort(Array1, Array2));
    }
    public static String mergeSort(int arr1[], int arr2[])
    {
        int len1 = arr1.length, len2 = arr2.length;
        int newArr[] = new int[len1 + len2];
        int count1 = 0, count2 = 0, i = 0;
        while (count1 < len1 && count2 < len2)
            if (arr1[count1] < arr2[count2])
                newArr[i++] = arr1[count1++];
                else
                newArr[i++] = arr2[count2++];
        while (count1 < len1)
            newArr[i++] = arr1[count1++];
        while (count2 < len2)
            newArr[i++] = arr2[count2++];
        return Arrays.toString(newArr);
    }
}