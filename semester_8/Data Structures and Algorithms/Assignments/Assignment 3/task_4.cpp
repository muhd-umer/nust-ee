/*
Implement a max-priority queue using the max-heap data structure in C++. Include functions/methods for the following operations:
1.	Inserting an element with a priority.
2.	Extracting the maximum priority element.
3.	Displaying the elements in the priority queue.
4.	Increasing the priority of an element in the queue.
5.	Discuss some applications of the implemented priority queue using the heap data structure.
*/

#include <climits>
#include <iostream>
using namespace std;

// Max Heap Class; arrays start from index 1
class MaxHeap {
   private:
    int *heap;
    int size;
    int capacity;

   public:
    MaxHeap(int total_capacity) {
        capacity = total_capacity;
        size = 0;
        heap = new int[capacity + 1];
        heap[0] = INT_MAX;  // dummy value
    }

    // Helper functions
    int parent(int i) {
        return i / 2;
    }
    int left_child(int i) {
        return 2 * i;
    }
    int right_child(int i) {
        return 2 * i + 1;
    }

    ~MaxHeap() {
        delete[] heap;
    }

    // heapify the subtree rooted at i
    void max_heapify(int i) {
        int left = left_child(i);
        int right = right_child(i);
        int largest = i;

        if (left <= size && heap[left] > heap[i]) {
            largest = left;
        }
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            max_heapify(largest);
        }
    }

    // insert an element with a priority
    void insert(int key) {
        if (size == capacity) {
            cout << "Overflow: Heap is full\n";
            return;
        }

        size++;
        heap[size] = key;

        int i = size;
        while (i > 1 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // extract the maximum priority element
    int extract_max() {
        if (size == 0) {
            cout << "Underflow: Heap is empty\n";
            return INT_MIN;
        }

        int max = heap[1];
        heap[1] = heap[size];
        size--;

        max_heapify(1);

        return max;
    }

    // display the elements in the priority queue
    void display() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        cout << "\n** Priority Queue: ";
        for (int i = 1; i <= size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // increase the priority of an element in the queue
    void increase_priority(int i, int new_key) {
        if (i > size) {
            cout << "Invalid index\n";
            return;
        }

        if (new_key < heap[i]) {
            cout << "New key is smaller than the current key\n";
            return;
        }

        heap[i] = new_key;

        while (i > 1 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};

int main() {
    MaxHeap maxHeap(10);
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(15);
    maxHeap.insert(5);
    maxHeap.insert(4);
    maxHeap.insert(45);

    cout << "Max-Heap array: ";
    maxHeap.display();

    cout << "\nExtracted max: " << maxHeap.extract_max() << endl;

    cout << "\nMax-Heap array after extracting max: ";
    maxHeap.display();

    maxHeap.increase_priority(2, 20);
    cout << "\nMax-Heap array after increasing key: ";
    maxHeap.display();

    return 0;
}