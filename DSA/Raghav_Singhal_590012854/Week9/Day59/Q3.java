class Q3 {
    private static boolean isValidHeap(int[] arr) {
        int n = arr.length;
        for (int i = 0; i <= (n - 2) / 2; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[i] < arr[left]) return false;
            if (right < n && arr[i] < arr[right]) return false;
        }
        return true;
    }

    public static boolean areHeapsIdentical(int[] arr1, int[] arr2) {
        
        if (arr1.length != arr2.length) return false;

        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != arr2[i]) return false;
        }

        return isValidHeap(arr1) && isValidHeap(arr2);
    }

    public static void main(String[] args) {
        int[] arr1 = {10, 9, 8};
        int[] arr2 = {10, 9, 8};
        System.out.println(areHeapsIdentical(arr1, arr2)); 

        int[] arr3 = {10, 9, 8};
        int[] arr4 = {10, 8, 9};
        System.out.println(areHeapsIdentical(arr3, arr4)); 
    }
}
