//   1.  The bug in the 'heapifyUp' condition is the placement of 'index = parent'. Currently, even when no swaps happens, 'index' still
//       updates which causes wrong behaviour.

//   2.  We must swap before moving 'index' to parent because if we move 'index' up without swapping, the heap property can be violated.
//       Swapping ensures that at every step, the Max heap condition (parent >= child) is restored before continuing upward.

//   3. Debugged code - 

//        #include <stdio.h>
//
//        void heapifyUp(int heap[], int index)
//        {
//            while (index > 1)
//            {
//                int parent = index / 2;
//                if (heap[parent] < heap[index])
//                {
//                    int temp = heap[parent];
//                    heap[parent] = heap[index];
//                    heap[index] = temp;
//                }
//                index = parent;
//            }
//        }
//
//        void insert(int heap[], int *size, int value)
//        {
//            (*size)++;
//            heap[*size] = value;
//            heapifyUp(heap, *size);
//        }
//        int main()
//        {
//            int heap[100] = {0, 50, 30, 40, 10, 20}; // 1-indexed
//            int size = 5;
//            insert(heap, &size, 60);
//            for (int i = 1; i <= size; i++)
//            {
//                printf("%d ", heap[i]);
//            }
//            return 0;
//        }
