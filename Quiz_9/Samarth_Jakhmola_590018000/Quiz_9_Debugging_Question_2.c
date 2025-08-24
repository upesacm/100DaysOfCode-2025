//   1.  Since the array actually has 7 elements, when we set 'size' as 6, the last element '35' gets ignored when we delete.

//   2.  The root is tthe minimum element. After removing it, we temporarily fill it with the last element to avoid creating a hole. Then 
//       we heapify down to restore the heap property. This keeps the array compact and ensures O(log n) deletion.

//   3.  Debugged code -

//        #include <stdio.h>
//        void heapifyDown(int heap[], int size, int index)
//        {
//            int largest = index;
//            int left = 2 * index;
//            int right = 2 * index + 1;
//            if (left <= size && heap[left] > heap[largest])
//                largest = left;
//            if (right <= size && heap[right] > heap[largest])
//                largest = right;
//            if (largest != index)
//            {
//                int temp = heap[index];
//                heap[index] = heap[largest];
//                heap[largest] = temp;
//                heapifyDown(heap, size, largest);
//            }
//        }
//        void deleteMax(int heap[], int *size)
//        {
//            if (*size == 0)
//                return;
//            heap[1] = heap[*size];
//            (*size)--;
//            heapifyDown(heap, *size, 1);
//        }
//        int main()
//        {
//            int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
//            int size = 7;  //  Fix : There are 7 elements, not 6.
//            deleteMax(heap, &size);
//            for (int i = 1; i <= size; i++)
//            {
//                printf("%d ", heap[i]);
//            }
//            return 0;
//        }
