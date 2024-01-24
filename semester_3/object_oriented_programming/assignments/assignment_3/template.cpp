// Program to sort an array of ten elements
// that can be either of int, float, double
// datatype, sorting would work regardless
// *EXCLUDING CHARS as sorting an array of
// char is pointless

// USING TEMPLATES

#include <iostream>
using namespace std;

// Template formed so that sorting of any
// type variable is possible

template <typename T>
class ArrAssignment;

template <typename T>
ostream& operator+=(ostream&, const ArrAssignment<T>&);

template <typename T>
class ArrAssignment {
private:
    int n;

public:
    ArrAssignment(int size) { n = size; }

    // Sorting function
    void sortArray(T arr[])
    {
        // to check for validity of sortness
        bool b = true;
        while (b) {
            b = false;
            for (int i = 0; i < n - 1; i++) {
                // sorting algorithm
                if (arr[i] > arr[i + 1]) {
                    T temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    b = true;
                }
            }
        }
    }

    // Display Function
    void printArray(T arr[])
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << "\t";
        cout << endl;
    }

    // template<>
    friend ostream& operator+=<T>(ostream&, const ArrAssignment<T>&);
};

template <typename T>
ostream& operator+=(ostream& out, const ArrAssignment<T>& e)
{
    cout << "\nCurrent Array Size: ";
    return out << e.n * e.n;
}

// Code to drive the above template
int main()
{
    // To check for all numerical data types
    ArrAssignment<int> a(8); // 8, 9, 10 represent size of array
    ArrAssignment<float> b(9);
    ArrAssignment<double> c(10);

    // Testint the sorting algorithm through templates
    // upon the aforementioned data types
    int intArr[] = { 41, -55, 151, -171, 229, -31, 0, 455 };
    a.sortArray(intArr);
    cout << "\nSorted Int Array:\n";
    a.printArray(intArr);

    float floatArr[] = { 46.5, 73.6, 11.5, 87.6, 8.6, 52.8, 
        42.8, 26.5, 1.1 };
    b.sortArray(floatArr);
    cout << "\nSorted Float Array:\n";
    b.printArray(floatArr);

    double doubleArr[] = { 12.553, 6458.2, 2, 91.23, 12.787,
        132.2, 0.00, 971.23, 12.551, 682.2 };
    c.sortArray(doubleArr);
    cout << "\nSorted Double Array:\n";
    c.printArray(doubleArr);

    // Operator overloading that returns the square
    // of number of elements present in each array
    cout << "\nArray Size of a: ";
    cout += a;
    cout << "\nArray Size of b: ";
    cout += b;
    cout << "\nArray Size of c: ";
    cout += c;

    return 0;
}