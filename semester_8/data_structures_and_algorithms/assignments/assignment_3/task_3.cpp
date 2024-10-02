/*
1.	Compare the time complexity of the two sorting algorithms you implemented.
2.	Discuss the best-case, average-case, and worst-case scenarios for merge sort and heap sort algorithms.
3.	Analyze and explain the advantages and disadvantages of each algorithm.
*/

#include <time.h>

#include <iostream>
using namespace std;

// Recursive merge_sort and merge functions
void merge(int arr[], int first, int mid, int last) {
    int n1 = mid - first + 1;  // elements in the first half
    int n2 = last - mid;       // elements in the second half
    int L[n1], R[n2];          // temporary arrays

    // copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[first + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // merge the temporary arrays back into arr[first..last]
    int i = 0, j = 0, k = first;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // copy the remaining elements, if any
    // only one of the following two while loops will execute
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(int arr[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

// Heap sort functions (assuming index starts from 0)
void heapify(int arr[], int n, int i) {
    int largest = i;    // initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // if left child is larger than root
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // one by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // move current root to end
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 10000;
    int arr_best[n], arr_avg[n], arr_worst[n];
    for (int i = 0; i < n; i++) {
        arr_best[i] = i;
        arr_avg[i] = rand() % n;
        arr_worst[i] = n - i;
    }

    int arr_best_c[n], arr_avg_c[n], arr_worst_c[n];  // copy of arrays
    for (int i = 0; i < n; i++) {
        arr_best_c[i] = arr_best[i];
        arr_avg_c[i] = arr_avg[i];
        arr_worst_c[i] = arr_worst[i];
    }

    clock_t start, end;
    double time_taken;

    // merge sort
    start = clock();
    merge_sort(arr_best, 0, n - 1);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Merge sort best-case time: " << time_taken << " seconds\n";

    start = clock();
    merge_sort(arr_avg, 0, n - 1);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Merge sort average-case time: " << time_taken << " seconds\n";

    start = clock();
    merge_sort(arr_worst, 0, n - 1);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Merge sort worst-case time: " << time_taken << " seconds\n";

    // heap sort
    start = clock();
    heap_sort(arr_best_c, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\nHeap sort best-case time: " << time_taken << " seconds\n";

    start = clock();
    heap_sort(arr_avg_c, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Heap sort average-case time: " << time_taken << " seconds\n";

    start = clock();
    heap_sort(arr_worst_c, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Heap sort worst-case time: " << time_taken << " seconds\n";

    return 0;
}