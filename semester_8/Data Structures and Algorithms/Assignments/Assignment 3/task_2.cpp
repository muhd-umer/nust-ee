/*
Implement merge sort and heap sort algorithms in C++. Provide well-commented
code along with explanations of your implementation choices.

You should show the application of your merge sort and heap sort implementations
on 3 examples each.
*/

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
    // Example 1
    int arr_merge[] = {12, 11, 13, 5, 6, 7};
    int arr_heap[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr_merge) / sizeof(arr_merge[0]);

    cout << "\nExample 1" << endl;
    cout << "=========" << endl;
    cout << "Merge Sort\n";
    merge_sort(arr_merge, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr_merge[i] << " ";
    cout << endl;

    cout << "Heap Sort\n";
    heap_sort(arr_heap, n);
    for (int i = 0; i < n; i++) cout << arr_heap[i] << " ";
    cout << endl;

    // Example 2
    int arr_merge2[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_heap2[] = {38, 27, 43, 3, 9, 82, 10};
    n = sizeof(arr_merge2) / sizeof(arr_merge2[0]);

    cout << "\nExample 2" << endl;
    cout << "=========" << endl;
    cout << "Merge Sort\n";
    merge_sort(arr_merge2, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr_merge2[i] << " ";
    cout << endl;

    cout << "Heap Sort\n";
    heap_sort(arr_heap2, n);
    for (int i = 0; i < n; i++) cout << arr_heap2[i] << " ";
    cout << endl;

    // Example 3
    int arr_merge3[] = {5, 2, 4, 6, 1, 3};
    int arr_heap3[] = {5, 2, 4, 6, 1, 3};
    n = sizeof(arr_merge3) / sizeof(arr_merge3[0]);

    cout << "\nExample 3" << endl;
    cout << "=========" << endl;
    cout << "Merge Sort\n";
    merge_sort(arr_merge3, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr_merge3[i] << " ";
    cout << endl;

    cout << "Heap Sort\n";
    heap_sort(arr_heap3, n);
    for (int i = 0; i < n; i++) cout << arr_heap3[i] << " ";
    cout << endl;

    return 0;
}