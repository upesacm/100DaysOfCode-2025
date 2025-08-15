#include <stdio.h>
#include <limits.h>

struct HeapNode {
    int value;
    int from_array;
    int index_in_array;
};

void heapify(struct HeapNode heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].value < heap[smallest].value)
        smallest = left;
    if (right < n && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        struct HeapNode temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, n, smallest);
    }
}

int main() {
    int k, n;
    printf("Enter number of sorted arrays: ");
    scanf("%d", &k);

    int sizes[k];
    int total_size = 0;
    int arrays[k][100]; 

    for (int i = 0; i < k; i++) {
        printf("Enter size of array %d: ", i + 1);
        scanf("%d", &sizes[i]);
        total_size += sizes[i];
        printf("Enter %d elements (sorted):\n", sizes[i]);
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    struct HeapNode heap[k];
    int heap_size = 0;
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) {
            heap[heap_size].value = arrays[i][0];
            heap[heap_size].from_array = i;
            heap[heap_size].index_in_array = 0;
            heap_size++;
        }
    }

    for (int i = heap_size / 2 - 1; i >= 0; i--)
        heapify(heap, heap_size, i);

    int result[total_size];
    int res_index = 0;

    while (heap_size > 0) {
        struct HeapNode root = heap[0];
        result[res_index++] = root.value;

        if (root.index_in_array + 1 < sizes[root.from_array]) {
            heap[0].value = arrays[root.from_array][root.index_in_array + 1];
            heap[0].index_in_array++;
        } else {
            heap[0] = heap[heap_size - 1];
            heap_size--;
        }

        heapify(heap, heap_size, 0);
    }

    printf("Merged array: ");
    for (int i = 0; i < total_size; i++)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}
